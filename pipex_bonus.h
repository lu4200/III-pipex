/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:11:14 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 18:43:20 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);

void	ft_multipipe(t_struct *s);
void	ft_close_pipes(t_struct *s);
void	ft_do_cmd(char *av, t_struct *s);

char	*ft_gnl(void);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *h, const char *n, size_t len);

#endif