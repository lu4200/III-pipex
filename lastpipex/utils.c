/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:37 by lucas             #+#    #+#             */
/*   Updated: 2024/05/18 15:34:33 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (!allpath)
		exit(1);
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (check_access(s_cmd, exec))
			return (exec);
		free(exec);
	}
	ft_free_array(allpath);
	ft_free_array(s_cmd);
	return (cmd);
}

void	execute(char *cmd, char **env, int *p)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		if (is_slash(s_cmd[0]))
		{
			close_all(p);
			ft_putstr_fd("\033[31m[ERROR]\033[0m: No such file or Directory:", 2);
			ft_putendl_fd(s_cmd[0], 2);
		}
		else
		{
			close_all(p);
			ft_putstr_fd("\033[31m[ERROR]\033[0m: command not found >> ", 2);
			ft_putendl_fd(s_cmd[0], 2);
		}
		ft_free_array(s_cmd);
		exit(1);
	}
}

int	openfd_rights(char *argv, int param)
{
	int	file;

	file = 0;
	if (param == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC
				| O_APPEND | O_CLOEXEC, 0777);
	else if (param == 2)
		file = open(argv, O_RDONLY | O_CLOEXEC, 0777);
	if (file == -1)
		error();
	return (file);
}
