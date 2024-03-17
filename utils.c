/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:37 by lucas             #+#    #+#             */
/*   Updated: 2024/03/17 16:07:55 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *command, char **envp)
{
	char	**paths;
	char	*path_fnl;
	char	*part_path;
	int	index;
	
	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	paths = ft_split(envp[index] + 5, ':');
	index = 0;
	while (paths[index])
	{
		part_path = ft_strjoin(paths[i], command);
		path_fnl = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path_fnl, F_OK) == 0)
			return path_fnl;
		index ++;
	}
	return (0);
}