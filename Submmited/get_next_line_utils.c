/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:05:50 by jode-jes          #+#    #+#             */
/*   Updated: 2023/07/13 16:28:06 by jode-jes         ###   ########.fr       */
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
	//if ((unsigned char)stash[i] == (unsigned char)target) // I send it to valuation, but it is redundant, 
	//	return (&stash[i]); 								//once the first time it finds the \n, it will return
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
		stash = malloc(sizeof(char) * 1); // If stash is NULL, I need to allocate memory for the NULL terminator
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	j = 0; // I need to reset j to 0, because I will initialize the variable.
	join = (char *)malloc(sizeof(stash[0]) * (i + ft_strlen(buf) + 1)); //stash[0] is the same as *stash and it means the first element of the array. I need to use stash[0] because I want to allocate memory for the first element of the array, not for the whole array. 
	if (join == NULL)
		return (NULL);
	while (stash[j])
	{
		join[j] = stash[j];
		j++;
	}
	j = -1; // I need to reset j to -1 because I will increment it before using it. why? because I want to start from 0. and why I don't use 0 right away instead of -1? because I want to start from the end of stash,and thats only possible if I increment j before using it.
	while (buf[++j])	// I need to increment j before using it, because I want to start from 0.
		join[i + j] = buf[j]; // I need to use i + j, because I want to start from the end of stash. 
	join[i + j] = '\0';
	free(stash);
	return (join);
}
