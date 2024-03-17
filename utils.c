/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:37 by lucas             #+#    #+#             */
/*   Updated: 2024/03/17 18:04:02 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	syntax_error(int multpipe)
{
	ft_putstr_fd("Error: Argument invalid", 2);
	if (multpipe)
	{
		//handle whith bonus part
	}
	else
	{
		ft_putstr_fd("prototype: ./pipex file_in cmd1 cmd2 file_out", 2);
	}
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("Error :/");
	exit(EXIT_FAILURE);
}

char	*find_path(char *command, char **envp)
{
	char	**paths;
	char	*path_fnl;
	char	*part_path;
	int		index;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	paths = ft_split(envp[index] + 5, ':');
	/*+5 to skip "PATH="*/
	index = 0;
	while (paths[index])
	{
		part_path = ft_strjoin(paths[index], command);
		path_fnl = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path_fnl, F_OK) == 0)
			return (path_fnl);
		index ++;
	}
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
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
		file = open(argv, O_WRONLY | __O_CLOEXEC, 0777);
	if (file == -1)
		error();
	return file;
}