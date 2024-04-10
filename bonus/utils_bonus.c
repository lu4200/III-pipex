/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:01:36 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/10 15:06:06 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// FROM MANDATORY //

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_array(s_cmd);
			return (	int	fd;

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
	ft_do_cmd(s->av[2], s);exec);
		}
		free(exec);
	}
	ft_free_array(allpath);
	ft_free_array(s_cmd);
	return (cmd);
}

