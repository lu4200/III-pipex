/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:00:06 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 19:36:22 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


void	ft_close_pipes(t_struct *s)
{
	int	i;

	i = -1;
	if (s->multipipe && s->ac - s->count > 1)
	{
		while (++i < s->ac - s->count)
		{
			close(s->multipipe[i][0]);
			close(s->multipipe[i][1]);
		}
		i = -1;
		while (++i < s->ac - s->count)
			free(s->multipipe[i]);
		free(s->multipipe);
	}
	close(s->pipe[0]);
	close(s->pipe[1]);
}

void	ft_create_pipes(t_struct *s)
{
	int	i;

	i = -1;
	s->multipipe = malloc(sizeof(int *) * s->count);
	if (!s->multipipe)
		exit (1);
	while (++i < s->count)
	{
		s->multipipe[i] = malloc(sizeof(int) * 2);
		if (!s->multipipe[i])
			exit (1);
		pipe(s->multipipe[i]);
	}
}

void	ft_multipipe(t_struct *s)
{
	int	i;
	int	pid;

	i = -1;
	s->count = 5;
	if (s->flag)
		s->count++;
	ft_create_pipes(s);
	while (++i < s->ac - s->count)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i != 0)
				dup2(s->multipipe[i - 1][0], 0);
			dup2(s->multipipe[i][1], 1);
			ft_close_pipes(s);
			if (s->flag)
				ft_do_cmd(s->av[i + 4], s);
			ft_do_cmd(s->av[i + 3], s);
		}
	}
	dup2(s->multipipe[i - 1][0], 0);
}
