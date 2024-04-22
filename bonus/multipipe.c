/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:00:06 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/22 14:25:52 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_pipes(t_struct *s)
{
	int	i;

	i = -1;
	if (s->multipipe)
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