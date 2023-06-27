/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:39:34 by jode-jes          #+#    #+#             */
/*   Updated: 2023/06/27 03:19:11 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#include "get_next_line.h"

char *ft_read_line(int fd, char *stash)
{
    char *buf; // Temporary buffer to read data from the file
    int nbytes_read; // Number of bytes read

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // Allocate memory for the temporary buffer
    if (!buf)
        return (NULL);
    nbytes_read = 1;
    while (!ft_strchr(stash, '\n') && nbytes_read != 0) // Continue reading until a newline is found in the stash or end of file is reached
    {
        nbytes_read = read(fd, buf, BUFFER_SIZE); // Read data from the file into the buffer
        if (nbytes_read == -1)
        {
            free(buf);
            free(stash);
            return (NULL);
        }
        buf[nbytes_read] = '\0'; // Null-terminate the buffer
        if (!buf)
            return (NULL);
        stash = ft_strjoin(stash, buf); // Append the buffer to the stash
    }
    free(buf);
    return (stash);
}

char *ft_get_line(char *stash)
{
    int i;
    char *line; // Extracted line

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n') // Find the newline character or end of stash
        i++;
    if (stash[i] == '\0')
        line = (char *)malloc(sizeof(char) * (i + 1)); // Allocate memory for the line
    else
        line = (char *)malloc(sizeof(char) * (i + 2)); // Allocate memory for the line including newline character
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n') // Copy characters from stash to the line
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n'; // Append the newline character if present
    line[i] = '\0'; // Null-terminate the line
    return (line);
}

char *ft_new_line(char *stash)
{
    int i;
    int j;
    char *newline; // Remaining data after the newline character

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n') // Find the newline character
        i++;
    if (!stash[i]) // If newline character is not found
    {
        free(stash);
        return (NULL);
    }
    newline = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1)); // Allocate memory for the remaining stash after the newline character
    if (!newline)
        return (NULL);
    i++;
    while (stash[i]) // Copy remaining characters from stash to the new string
        newline[j++] = stash[i++];
    newline[j] = '\0'; // Null-terminate the new string
    free(stash);
    return (newline);
}

char *get_next_line(int fd)
{
    char *line; // Line to be returned
    static char *stash; // Static stash to store data between function calls

    if (fd < 0 || BUFFER_SIZE <= 0) // Check if file descriptor is valid and buffer size is positive
        return (0);
    stash = ft_read_line(fd, stash); // Read data from the file and update the stash
    if (!stash)
        return (NULL);
    line = ft_get_line(stash); // Extract a line from the stash
    stash = ft_new_line(stash); // Extract remaining data after the newline character
    return (line);
}


int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY); // Open the file for reading
    if (fd == -1)
    {
        // Handle file opening error
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) // Call get_next_line in a loop until it returns NULL
    {
        // Process the line (e.g., print it)
        printf("%s\n", line);

        free(line); // Free the memory allocated for the line
    }

    close(fd); // Close the file

    return 0;
} 