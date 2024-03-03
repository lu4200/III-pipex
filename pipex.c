/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:35:12 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/03 07:57:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int fd[2])
{
	dup2(fd[1], STDOUT_FILENO); // STDOUT to pipe
	close(fd[0]);

	execve("/bin/sh", argv, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(char **argv, char **envp, int fd[2])
{
	dup2(fd[0], STDIN_FILENO); // STDIN to pipe
	close(fd[1]);

	execve("/bin/sh", argv, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}