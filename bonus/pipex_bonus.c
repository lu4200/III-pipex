/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:53:39 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 15:06:48 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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
	dup2(fd, 0);  // STDIN_FILENO
	dup2(s->pipe[1], 1); // STDOUT_FILENO
	close(fd);
	ft_close_pipes(s);
	ft_do_cmd(s->av[2], s);
}
// FROM MANDATORY //

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_array(s_cmd);
		exit(0);
	}
}

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
	while (ft_strnstr(env[s.n], "PATH=", 5) == NULL)
		if (env[++s.n] == NULL)
			exit(write(1, "error: unfound path\n", 18));
	if (ft_strcmp(s.av[1], "here_doc") == 0)
		ft_here_doc(&s);
	pipe(s.pipe);
	pid = fork();
	if (pid == 0)
		ft_first_proc(&s);
	ft_second_proc(&s);
}
