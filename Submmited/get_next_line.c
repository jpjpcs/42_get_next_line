/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:39:34 by jode-jes          #+#    #+#             */
/*   Updated: 2023/07/13 16:03:36 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1- ACABAR DE ESCREVER EXPLICAÇÃO DO GNL no caderno e REPRODUZIR GET_NEXT_LINE
// 2 - VER PARTE BONUS
// 3- VERIFICAR TESTES TRIPOILLE E FRANCINETTE 
//- CORRIGIR NORMINETTE E VERIFICAR LEAKS- TD OK -> ENTREGAR
// Dúvidas: 
// 1 - Stdin (standard input) files
// 2 - Read multiple files starting where it left
// 3 - How bonus changes make this? What changed?
// 4 - Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?
//5 - What it means "undefined behavior if the file pointed to
//by the file descriptor changed since the last call"
// 6 - How the code is dealing with that "undefined behavior when reading
//a binary file."
// 7 - Bonus: That was already done: "Develop get_next_line() using only one static variable"
// 8 - what this means "read from a different fd per call without losing the reading thread of each
//file descriptor or returning a line from another fd.
//It means that you should be able to call get_next_line() to read from fd 3, then
//fd 4, then 5, then once again 3, once again 4, and so forth."
// 9 - What this means " A file descriptor does not only point to regular files.
//Be smart and cross-check with your peers. " 
// 10 - How? "add your get_next_line() to your libft"


//GENERAL EXPLANATION:
//1 - The get_next_line function takes a file descriptor (fd) as an 
//argument and initializes a static buffer variable (stash) to 
//store the data read from the file.
//2 - It first performs some basic error checks to ensure that the 
//file descriptor is valid (fd >= 0) and the buffer size is positive 
//(BUFFER_SIZE > 0). If any of these conditions are not met, it returns 0 
//or NULL to indicate an error.
//3 - Next, it calls the ft_read_line function, passing the file descriptor 
//and the stash. The ft_read_line function reads data from the file 
//into the buffer until it encounters a newline character or reaches the 
//end of the file.
//4 - Once the data is read into the stash, the ft_get_line function is called,
//	passing the stash as an argument.
//This function extracts a line from the stah up to the newline character or 
//the end of the buffer. It dynamically allocates memory for the extracted line 
//and copies the characters from the stash to the line.
//5 - After extracting the line, the ft_new_line function is called,
//	passing again the stash as an argument. This function extracts the 
//remaining data after the newline character from the stash. 
//It dynamically allocates memory for the remaining data,
//	copies the characters to a new string (the newline), 
//and frees the memory previously allocated for the stash.
//6 - The extracted line is returned from the get_next_line function.
//7 - When the get_next_line function is called again,
//	it resumes from where it left off, 
//using the static variable (stash) to retrieve the next line from the file. 
//The static stash retains the remaining data from the previous call,
//	and any new data read from the file is appended to it. 
//This allows the function to continue reading lines from the file until 
//the end is reached.
//8- The process continues until there are no more lines to read or an 
//error occurs.
//
//It's important to note that this implementation assumes that the file 
//being read contains lines terminated by newline characters ('\n'). 
//The code reads and processes the file one line at a time,
//and each call to get_next_line retrieves the next line from the file. 
//The static buffer retains any remaining data after the last newline 
//character, ensuring that it's included in the subsequent calls to 
//get_next_line.
//
//
//
//READ LINE
//
//Function general explanation: 
//ft_read_line function reads data from the file descriptor (fd) into 
//a temporary buffer(buf),and appends it to the existing string that 
//accumulates what its read (stash) until a newline character is encountered
//or the end of file is reached.It dynamically allocates memory for the 
//buf (buffer) based on the defined BUFFER_SIZE in the header file.
//The function checks for errors in memory allocation and the read system call.
//The buf (buffer) is null-terminated by setting buf[bytes] = '\0'.
//Finally, the function frees the memory allocated for the  buf (buffer) 
//and returns the updated string stash (stash means accumulate).
//
//Inside function:
// Line 1 - Temporary buffer to read data from the file
// Line 2 - Number of bytes read
// Line 3 - Allocate memory for the temporary buffer
// Line 7 - Continue reading until a newline is found in the stash or 
//end of file is reached
// Line 9 - // Read data from the file into the buffer
// Line 15 - Null-terminate the buffer
// Line 18 - Append the buffer to the stash
//
//
//
// GET LINE
//
//Function general explanation:
//ft_get_line function extracts a line from the provided stash until a 
//newline character ('\n') or the end of the buffer is encountered.
//It dynamically allocates memory for the extracted line, considering 
//the presence of the newline character.
//The function copies characters from the stash variable to the line 
//until the newline character or end of the stash is reached.
//If a newline character is present, it appends the newline character to the
// line. The line is null-terminated by setting line[i] = '\0'.
//The function returns the extracted line.
//
//Inside function:
// Line 2 - Extracted line
// Line 6 - Find the newline character or end of stash
// Line 9 - Allocate memory for the line
// Line 11 - Allocate memory for the line including newline character
// Line 16 - Copy characters from stash to the line
// Line 21 - Append the newline character if present
// Line 22 - Null-terminate the line
//
//
//
// NEW LINE
//
//Function general explanation:
//ft_new_line function extracts the remaining data from the stash after 
//the newline character. So get_line will read and store the data before \n, 
//and New_Line will do it after the \n.
//It searches for the newline character in the stash and determines the 
//remaining length of the stash after the newline.
//The function dynamically allocates memory for the remaining data.
//It copies the remaining characters from the stash to the new string 
//that is the newline (or the nextline after the previous one).
//The newline is null-terminated by setting newline[j] = '\0'.
//Finally, the function frees the memory allocated for the stash 
//and returns the remaining data.
//
//Inside function:
// Line 3 - Remaining data after the newline character
// Line 7 - Find the newline character
// Line 8 - If newline character is not found
// Line 14 - Allocate memory for the remaining stash after the newline character
// Line 19 - Copy remaining characters from stash to the new string
// Line 20 - Null-terminate the new string
//
//
//
//GET NEXT LINE
//
//Function general explanation:
//get_next_line function is the entry point for retrieving lines from a file.
//It takes a file descriptor (fd) as an argument.
//The function checks if the file descriptor is valid and if the buffer size 
//is positive.It calls ft_read_line to read data from the file into the stash.
//Then, it calls ft_get_line to extract a line from the stash. Finally,
//it calls ft_new_line to extract the remaining data after the line from the 
//stash.The function returns the extracted line. It repeats the process of 
//reading lines from a file by utilizing a static buffer to store the data 
//between function calls. Here's an explanation of how it works:
//
//Inside function:
// Line 1 - Line to be returned
// Line 2 - Static stash to store data between function calls
// Line 3 - Check if file descriptor is valid and buffer size is positive
// Line 5 - Read data from the file and update the stash
// Line 8 - Extract a line from the stash
// Line 9 - Extract remaining data after the newline character

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

// READ LINE
//
//Function general explanation: 
//ft_read_line function reads data from the file descriptor (fd) into 
//a temporary buffer(buf),and appends it to the existing string that 
//accumulates what its read (stash) until a newline character is encountered
//or the end of file is reached.It dynamically allocates memory for the 
//buf (buffer) based on the defined BUFFER_SIZE in the header file.
//The function checks for errors in memory allocation and the read system call.
//The buf (buffer) is null-terminated by setting buf[bytes] = '\0'.
//Finally, the function frees the memory allocated for the  buf (buffer) 
//and returns the updated string stash (stash means accumulate).
char	*ft_read_line(int fd, char *stash)
{
	char	*buf; // Line 1 - Temporary buffer to read data from the file
	int		nbytes_read; // Line 2 - Number of bytes read

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // Line 3 - Allocate memory for the temporary buffer
	if (!buf)
		return (NULL);
	nbytes_read = 1; // It is initialized to 1 to enter the while loop at least the first time, to check empty files.
	while (!ft_strchr(stash, '\n') && nbytes_read != 0) // Line 7 - Continue reading until a newline is found in the stash or 
	{													//end of file is reached
		nbytes_read = read(fd, buf, BUFFER_SIZE); 	// Line 9 - // Read data from the file into the buffer	
		if (nbytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[nbytes_read] = '\0'; // Line 15 - Null-terminate the buffer
		if (!buf)
			return (NULL);
		stash = ft_strjoin(stash, buf); // Line 18 - Append the buffer to the stash	
	}
	free(buf);
	return (stash);
}

// GET LINE
//
//Function general explanation:
//ft_get_line function extracts a line from the provided stash until a 
//newline character ('\n') or the end of the buffer is encountered.
//It dynamically allocates memory for the extracted line, considering 
//the presence of the newline character.
//The function copies characters from the stash variable to the line 
//until the newline character or end of the stash is reached.
//If a newline character is present, it appends the newline character to the
// line. The line is null-terminated by setting line[i] = '\0'.
//The function returns the extracted line.
//
//Inside function:
// Line 2 - Extracted line
// Line 6 - Find the newline character or end of stash
// Line 9 - Allocate memory for the line
// Line 11 - Allocate memory for the line including newline character
// Line 16 - Copy characters from stash to the line
// Line 21 - Append the newline character if present
// Line 22 - Null-terminate the line
//
char	*ft_get_line(char *stash)
{
	int		i;
	char	*line; // Line 2 - Extracted line

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')// Line 6 - Find the newline character or end of stash
		i++;
	if (stash[i] == '\0')								// This line is executed when the newline character ('\n') is not present in the stash, 
		line = (char *)malloc(sizeof(char) * (i + 1)); //indicating that the extracted line reaches the end of the stash string. In this case,
	else											//the memory allocation is i + 1 to accommodate the characters in the line and the null-terminating character ('\0'). 
		line = (char *)malloc(sizeof(char) * (i + 2));	// This line is executed when the newline character is present in the stash, indicating that the extracted line 
	if (!line)										//is not the last line in the stash and there are more characters after the newline. In this case, the memory allocation 
		return (NULL);							// is i + 2 to accommodate the characters in the line, the newline character ('\n'), and the null-terminating character ('\0').
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i]; // Line 16 - Copy characters from stash to the line
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n'; // Line 21 - Append the newline character if present
	line[i] = '\0'; // Line 22 - Null-terminate the line
	return (line);
}

// NEW LINE
//
//Function general explanation:
//ft_new_line function extracts the remaining data from the stash after 
//the newline character. So get_line will read and store the data before \n, 
//and New_Line will do it after the \n.
//It searches for the newline character in the stash and determines the 
//remaining length of the stash after the newline.
//The function dynamically allocates memory for the remaining data.
//It copies the remaining characters from the stash to the new string 
//that is the newline (or the nextline after the previous one).
//The newline is null-terminated by setting newline[j] = '\0'.
//Finally, the function frees the memory allocated for the stash 
//and returns the remaining data.
//
//Inside function:
// Line 3 - Remaining data after the newline character
// Line 7 - Find the newline character
// Line 8 - If newline character is not found
// Line 14 - Allocate memory for the remaining stash after the newline character
// Line 19 - Copy remaining characters from stash to the new string
// Line 20 - Null-terminate the new string
char	*ft_new_line(char *stash)
{
	int		i;
	int		j;
	char	*newline;// Line 3 - Remaining data after the newline character

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n') // Line 7 - Find the newline character
		i++; // Line 8 - If newline character is not found
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));// Line 14 - Allocate memory for the remaining stash after the newline character
	if (!newline)
		return (NULL);
	i++;
	while (stash[i])
		newline[j++] = stash[i++]; // Line 19 - Copy remaining characters from stash to the new string
	newline[j] = '\0';// Line 20 - Null-terminate the new string
	free(stash);
	return (newline);
}

//GET NEXT LINE
//
//Function general explanation:
//get_next_line function is the entry point for retrieving lines from a file.
//It takes a file descriptor (fd) as an argument.
//The function checks if the file descriptor is valid and if the buffer size 
//is positive.It calls ft_read_line to read data from the file into the stash.
//Then, it calls ft_get_line to extract a line from the stash. Finally,
//it calls ft_new_line to extract the remaining data after the line from the 
//stash.The function returns the extracted line. It repeats the process of 
//reading lines from a file by utilizing a static buffer to store the data 
//between function calls. Here's an explanation of how it works:
//
//Inside function:
// Line 1 - Line to be returned
// Line 2 - Static stash to store data between function calls
// Line 3 - Check if file descriptor is valid (predefined fd = 0:stdin, =1: stdout, =2:stderr) 
// and buffer size is positive and buffer size is positive
// Line 5 - Read data from the file and update the stash
// Line 8 - Extract a line from the stash
// Line 9 - Extract remaining data after the newline character
char	*get_next_line(int fd)
{
	char		*line;// Line 1 - Line to be returned
	static char	*stash;// Line 2 - Static stash to store data between function calls

	if (fd < 0 || BUFFER_SIZE <= 0)// Line 3 - Check if file descriptor is valid (predefined fd = 0:stdin, =1: stdout, =2:stderr) and buffer size is positive
		return (0);					//and buffer size is positive
	stash = ft_read_line(fd, stash); // Line 5 - Read data from the file and update the stash
	if (!stash)
		return (NULL);
	line = ft_get_line(stash); // Line 8 - Extract a line from the stash
	stash = ft_new_line(stash); // Line 9 - Extract remaining data after the newline character
	return (line);
}

int	main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY); // Open the file for reading
    if (fd == -1)
    {
        // Handle file opening error
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
	// Call get_next_line in a loop until it returns NULL
    {
        // Process the line (e.g., print it)
        printf("%s\n", line);

        free(line); // Free the memory allocated for the line
    }

    close(fd); // Close the file

    return (0);
}