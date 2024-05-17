/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:18:12 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/17 15:43:01 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_slash(const char *haystack)
{
	char	needle;
	int		i;

	i = 0;
	needle = '/';
	if (haystack)
	{
		while (haystack[i])
		{
			if (haystack[i] == needle)
				return (1);
			i++;
		}
	}
	return (0);
}

static char	*ft_strstr(char *haystack, char *needle)
{
	int	index_meule;
	int	index_aiguille;

	index_meule = 0;
	index_aiguille = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[index_meule])
	{
		if (needle[index_aiguille] != '\0'
			&& haystack[index_meule + index_aiguille] == needle[index_aiguille])
			index_aiguille++;
		else if (needle[index_aiguille] == '\0')
			return ((char *)&haystack[index_meule]);
		else
		{
			index_aiguille = 0;
			index_meule++;
		}
	}
	return (NULL);
}

int	is_path_set(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (env)
	{
		while (env[i])
		{
			if (ft_strstr(env[i], "\nPATH="))
				return (1);
			i++;
		}
	}
	return (0);
}

void	path_error(void)
{
	ft_putstr_fd("\033[31m[ERROR]\033[0m : PATH is unset \n", 2);
	exit(EXIT_FAILURE);
}
