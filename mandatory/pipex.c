/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:35:12 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/01 18:26:28 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *p)
{
	int		filein;

	if (access(argv[1], F_OK) == -1)
	{
		perror("\033[31m[FATAL]\033[0m: File does not exist");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		perror("\033[31m[FATAL]\033[0m: Cannot read file");
		exit(EXIT_FAILURE);
	}
	filein = openfd_rights(argv[1], 2);
	if (filein == -1)
		error();
	dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(p[READ_END]);
	close(filein);
	execute(argv[2], envp);
}

void	child_process2(char **argv, char **envp, int *p)
{
	int		fileout;

	fileout = openfd_rights(argv[4], 1);
	if (fileout == -1)
		error();
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	static int	test = 0;
	int			fd[2];

	while (test < argc)
	{
		if (!argv[test] || *argv[test] == '\0' || argc == 1)
			syntax_error();
		test++;
	}
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		exec_child(argv, envp, fd);
		exec_child2(argv, envp, fd);
		close_all(fd);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
