/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:37 by lucas             #+#    #+#             */
/*   Updated: 2024/03/18 18:54:32 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	syntax_error(void)
{
	ft_putstr_fd("Error: Argument invalid", 2);
	ft_putstr_fd("prototype: ./pipex file_in cmd1 cmd2 file_out", 2);
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("Error :/");
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		ft_free_array(cmd);
		error();
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_array(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free_array(cmd);
		error();
	}
	free(path);
	ft_free_array(cmd);
}

int	openfd_rights(char *argv, int param)
{
	int	file;

	file = 0;
	if (param == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND | __O_CLOEXEC, 0777);
	else if (param == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | __O_CLOEXEC, 0777);
	else if (param == 2)
		file = open(argv, O_RDONLY | __O_CLOEXEC, 0777);
	if (file == -1)
		error();
	return (file);
}