/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:28:33 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/17 14:08:18 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	syntax_error(void)
{
	ft_putstr_fd("\033[31m[ERROR]\033[0m: Argument invalid ", 2);
	ft_putstr_fd("\nprototype: ./pipex file_in cmd1 cmd2 file_out", 2);
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("\033[31m[ERROR]\033[0m");
	exit(1);
}

void	env_error(void)
{
	ft_putstr_fd("\033[31m[ERROR]\033[0m : Env unset or invalid ", 2);
	exit(EXIT_SUCCESS);
}

void	type_error(char *s)
{
	if (s)
		perror(s);
	exit(EXIT_FAILURE);
}

char	*check_access(char **s_cmd, char *exec)
{
	if (access(exec, F_OK | X_OK) == 0)
	{
		ft_free_array(s_cmd);
		return (exec);
	}
	return (NULL);
}
