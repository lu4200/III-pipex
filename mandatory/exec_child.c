/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:49:58 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/01 18:19:47 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	exec_child(char **argv, char **envp, int *fd)
{
	pid_t		pid1;

	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child_process(argv, envp, fd);
}

void	exec_child2(char **argv, char **envp, int *fd)
{
	pid_t		pid2;

	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		child_process2(argv, envp, fd);
}
