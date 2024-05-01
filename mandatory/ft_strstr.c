/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:39:30 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/01 16:12:09 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	my_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return (1);
	if (*haystack == '\0')
		return (0);
	if (*haystack == *needle)
		return (my_strstr(haystack + 1, needle + 1));
	return (my_strstr(haystack + 1, needle));
}
