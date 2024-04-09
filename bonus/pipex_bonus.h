/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:54:18 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/09 16:56:20 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		n;
	int		ac;
	int		pid;
	int		flag;
	int		count;
	int		pipe[2];
	int		**multipipe;
	int		here_pipe[2];
	char	**av;
	char	**env;
}	t_struct;

#endif