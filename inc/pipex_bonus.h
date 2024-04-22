/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:54:18 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 15:18:05 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

void	ft_close_pipes(t_struct *s);
void	ft_create_pipes(t_struct *s);
void	ft_multipipe(t_struct *s);
void	ft_first_proc(t_struct *s);
void	execute(char *cmd, char **env);
void	ft_here_doc(t_struct *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *h, const char *n, size_t len);
int	ft_strlen(char *s);

#endif