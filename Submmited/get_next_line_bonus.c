/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:17:59 by jode-jes          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:22 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		nbytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nbytes_read = 1;
	while (!ft_strchr(stash, '\n') && nbytes_read != 0)
	{
		nbytes_read = read(fd, buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[nbytes_read] = '\0';
		if (!buf)
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_line(char *stash)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!newline)
		return (NULL);
	i++;
	while (stash[i])
		newline[j++] = stash[i++];
	newline[j] = '\0';
	free(stash);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FILES];

	if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE <= 0) // the first difference between mandatory and bonus is MAX_FILES (which is the max number of files that can be opened at the same time: 256). 
		return (NULL);									//I predefined to 500 in the header file.
	stash [fd] = ft_read_line(fd, stash[fd]); // the second difference is that I'm using fd position [fd] to store the stash of each file. 
	if (!stash[fd])				//this memorizes the line read from the file before passing to the new file to read (if there is one)
		return (NULL);	// 3rd difference is in the definition of the amount of files to read in the header file.
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_new_line(stash[fd]);
	return (line);
}

/* int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	// Abrir os arquivos de texto
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	// Ler linhas do primeiro arquivo
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("File 1: %s\n", line);
		free(line);
		line = get_next_line(fd1);
	}

	// Ler linhas do segundo arquivo
	line = get_next_line(fd2);
	while (line != NULL)
	{
		printf("File 2: %s\n", line);
		free(line);
		line = get_next_line(fd2);
	}

	// Ler linhas do terceiro arquivo
	line = get_next_line(fd3);
	while (line != NULL)
	{
		printf("File 3: %s\n", line);
		free(line);
		line = get_next_line(fd3);
	}

	// Fechar os arquivos
	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}
 */