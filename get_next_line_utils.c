/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:05:50 by jode-jes          #+#    #+#             */
/*   Updated: 2023/06/27 03:06:23 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *stash, int target)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if ((unsigned char)stash[i] == (unsigned char)target)
			return (&stash[i]);
		i++;
	}
	if ((unsigned char )stash[i] == (unsigned char)target)
		return (&stash[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char const *buf)
{
	int		i;
	int		j;
	char	*join;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	j = 0;
	join = (char *)malloc(sizeof(stash[0]) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (join == NULL)
		return (NULL);
	while (stash[j])
	{
		join[j] = stash[j];
		j++;
	}
	j = -1;
	while (buf[++j])
		join[i + j] = buf[j];
	free(stash);
	join[i + j] = '\0';
	return (join);
}