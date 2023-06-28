/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:14:08 by jode-jes          #+#    #+#             */
/*   Updated: 2023/06/28 17:16:50 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FILES
#  define MAX_FILES 500
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *str);
char	*ft_strchr(char *buffer, int target);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_get_line(char *buffer);
char	*ft_new_line(char *buffer);
size_t	ft_strlen(const char *str);

#endif