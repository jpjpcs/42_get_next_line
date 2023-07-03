# 42_get_next_line

## Get Next Line Resume

Is a program that reads and returns a line from a file descriptor each time it is called. It reads the file until it reaches its end.
The function returns a pointer to a string containing the line that was read, without the newline character \n. The function returns NULL when the end of file is reached or an error occurs. The function uses a static variable to store the remaining characters from the previous call, if any.

## Subject
Write a function that returns a line read from a file descriptor.

◦ Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

◦ Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

◦ Make sure that your function works as expected both when reading a file and when reading from the standard input.

◦ Please note that the returned line should include the terminating \n character, except if the end of the file was reached and does not end with a \n character

### Buffer Size
The size of the buffer used to read from the file descriptor. If not specified, the default value is 42. To set your own buffer size in the files, use the flag -D BUFFER_SIZE=n at time to compile de functons.

### Return value
◦ Read line: correct behavior.

◦ NULL: there is nothing else to read, or an error occurred.

## Tests:
Francinette: https://github.com/xicodomingues/francinette
gnlTester: https://github.com/Tripouille/gnlTester
