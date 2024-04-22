/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:30:55 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 19:44:10 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(t_struct *s)
{
	char	*tmp;
	char	*res;

	res = NULL;
	s->flag = 1;
	while (1)
	{
		write(1, "here_doc> ", 10);
		tmp = ft_gnl();
		if (ft_strcmp(tmp, s->av[2]) == 0)
			break ;
		res = ft_strjoin(res, tmp);
		free(tmp);
	}
	pipe(s->here_pipe);
	write(s->here_pipe[1], res, ft_strlen(res));
	close(s->here_pipe[1]);
	free(tmp);
	free(res);
}

void	ft_do_cmd(char *av, t_struct *s)
{
	int	i;

	i = -1;
	execve(ft_split(av, ' ')[0], ft_split(av, ' '), s->env);
	while (ft_split(s->env[s->n] + 5, ':')[++i])
		execve(ft_strjoin(ft_strjoin(ft_split(s->env[s->n] + 5, ':')[i], "/"),
				ft_split(av, ' ')[0]), ft_split(av, ' '), s->env);
	exit(write(2, "error: bad path\n", 16));
}

void	ft_second_proc(t_struct *s)
{
	int	fd;

	if (s->flag)
		fd = open(s->av[s->ac - 1], O_WRONLY | O_APPEND | O_CREAT, 422);
	else
		fd = open(s->av[s->ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 422);
	if (fd == -1)
		exit(write(1, "error: open file\n", 17));
	dup2(s->pipe[0], 0);
	if ((!s->flag && s->ac > 5) || (s->flag && s->ac > 6))
		ft_multipipe(s);
	dup2(fd, 1);
	close(fd);
	if ((!s->flag && s->ac > 5) || (s->flag && s->ac > 6))
		ft_close_pipes(s);
	close(s->pipe[0]);
	close(s->pipe[1]);
	ft_do_cmd(s->av[s->ac - 2], s);
}

void	ft_first_proc(t_struct *s)
{
	int	fd;

	if (s->flag)
	{
		dup2(s->here_pipe[0], 0);
		dup2(s->pipe[1], 1);
		ft_close_pipes(s);
		ft_do_cmd(s->av[3], s);
	}
	if (ft_strcmp(s->av[1], s->av[4]) == 0)
		fd = open(s->av[1], O_RDONLY | O_TRUNC);
	else
		fd = open(s->av[1], O_RDONLY);
	if (fd == -1)
		exit(write(1, "error: open file\n", 17));
	dup2(fd, 0);
	dup2(s->pipe[1], 1);
	close(fd);
	ft_close_pipes(s);
	ft_do_cmd(s->av[2], s);
}

int	main(int ac, char **av, char **env)
{
	t_struct	s;
	int			pid;

	if (ac < 5)
		return (1);
	s.n = 0;
	s.ac = ac;
	s.av = av;
	s.flag = 0;
	s.env = env;
	s.count = 0;
	while (ft_strnstr(env[s.n], "PATH=", 5) == NULL)
		if (env[++s.n] == NULL)
			exit(write(1, "error: unset path\n", 18));
	if (ft_strcmp(s.av[1], "here_doc") == 0)
		ft_here_doc(&s);
	pipe(s.pipe);
	pid = fork();
	if (pid == 0)
		ft_first_proc(&s);
	ft_second_proc(&s);
}
