# 42_get_next_line (char *get_next_line(int fd);)

# Resume

Is a program that reads and returns a line from a file descriptor each time it is called. It reads the file until it reaches its end.

The function returns a pointer to a string containing the line that was read, with the newline character \n. The function returns NULL when the end of file is reached or an error occurs. 

The function uses a static variable to store the remaining characters from the previous call, if any.

### Functions 
It is composed by 4 main functions (Get_Next_Line, Read_Line, Get_Line, Next_Line) and 3 helper functions (strchr, strlen, strjoin):

```markdown
Get_Next_Line: Creates buffer (buf) variable and stash (the static variable - stash mean accumulate), and calls also the other 4 main functions.
ft_read_line: Reads the Line to the buffer (buf), and copies that data from buffer to stash (static varibale) until it founds a \n.
ft_get_line: Extracts the first line from a string (the stash), up to the newline character or end of string.
ft_new_line: Extracts the remaining line from the string (stash) after the newline character. In each call it stores that value on the stash, and when the Get_Next_Line function is called, stash starts from the point it was read.
```

#### Example
In the phrase "I love to code \n at 42 school.", read_line reads n characters - defined by the buffer size - and store it at stash. If buffer size is 5, it will read 5 characters until it reaches "I love to code \n at " - that is 20 characters. 
After that, get line extracts it from stash until \n - ""I love to code \n". New_Line extracts after \n - " at 42 school.")

```markdown
ft_strlen: Calculates the length of a string.
ft_strchr: Locates the first occurrence of a character in a string (the character that we are searching. In the case above \n).
ft_strjoin: Concatenates two strings, dynamically allocating memory for the result.
```

### Bonus (difference between bonus and mandatory)
The only difference between the mandatory and bonus parts is the addition of support for multiple file descriptors (stash[MAX_FILES]). The stash array is used to store the accumulated data for each file descriptor separately, allowing simultaneous reading from multiple files.

The main difference between the mandatory and bonus parts is that the bonus part includes the additional functionality of handling multiple file descriptors, whereas the mandatory part only focuses on reading from a single file descriptor.

### Allowed functions
| Functions | Description                                                                                                  |
|-----------|--------------------------------------------------------------------------------------------------------------|
| malloc	| Allocates a block of memory of the specified size in bytes. Returns a pointer to the allocated memory or NULL.|
| free | Deallocates the previously allocated memory block. |
| read | Reads data from a file descriptor into a buffer. Returns the number of bytes read or -1 on error.|

### Forbidden functions
| Functions | Description                                                                                                  |
|-----------|--------------------------------------------------------------------------------------------------------------|
| ❌ libft |	Usage of our libft project library is NOT allowed. |
| lseek() | It stops where we left our reading. | 
| Global variables | Are forbidden because we can use it to substitute static variables. |

# Detailded Explanation
The get_next_line function takes a file descriptor (fd) as an argument and initializes a static buffer variable (buffer) to store the data read from the file.

It first performs some basic error checks to ensure that the file descriptor is valid (fd >= 0) and the buffer size is positive (BUFFER_SIZE > 0). If any of these conditions are not met, it returns 0 or NULL to indicate an error.

Next, it calls the ft_read_line function, passing the file descriptor and the buffer. The ft_read_line function reads data from the file into the buffer until it encounters a newline character or reaches the end of the file.

Once the data is read into the buffer, the ft_get_line function is called, passing the buffer as an argument. This function extracts a line from the buffer up to the newline character or the end of the buffer. It dynamically allocates memory for the extracted line and copies the characters from the buffer to the line.

After extracting the line, the ft_new_line function is called, passing the buffer as an argument. This function extracts the remaining data after the newline character from the buffer. It dynamically allocates memory for the remaining data, copies the characters to a new string, and frees the memory previously allocated for the buffer.

The extracted line is returned from the get_next_line function.

When the get_next_line function is called again, it resumes from where it left off, using the static buffer to retrieve the next line from the file. The static buffer retains the remaining data from the previous call, and any new data read from the file is appended to it. This allows the function to continue reading lines from the file until the end is reached.

The process continues until there are no more lines to read or an error occurs.

It's important to note that this implementation assumes that the file being read contains lines terminated by newline characters ('\n'). The code reads and processes the file one line at a time, and each call to get_next_line retrieves the next line from the file. The static buffer retains any remaining data after the last newline character, ensuring that it's included in the subsequent calls to get_next_line.

# Subject
Write a function that returns a line read from a file descriptor.

◦ Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

◦ Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

◦ Make sure that your function works as expected both when reading a file and when reading from the standard input.

◦ Please note that the returned line should include the terminating \n character, except if the end of the file was reached and does not end with a \n character

#### Buffer Size
The size of the buffer used to read from the file descriptor. If not specified, the default value is 42. To set your own buffer size in the files, use the flag -D BUFFER_SIZE=n at time to compile de functions.

#### Return value
◦ Read line: correct behavior.

◦ NULL: there is nothing else to read, or an error occurred.

# Videos
See this videos to help you clarify and understand this project better:
https://www.youtube.com/watch?v=-Mt2FdJjVno
https://www.youtube.com/watch?v=8E9siq7apUU

# Tests
Francinette: https://github.com/xicodomingues/francinette
gnlTester: https://github.com/Tripouille/gnlTester
