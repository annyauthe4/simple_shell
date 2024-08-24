#include "main.h"

/**
  * _getline - Reads an entire line of chars from an input stream
  * @lineptr: A pointer to a pointer to a buffer
  * @n: A pointer to a buffer size
  * @stream: The input (eg stdin or a file)
  *
  * Return: Number of chars read or -1 on error or EOF
  */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *new_ptr;
	ssize_t bytes_read;
	size_t i, j;
	char buffer[1];

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	i = 0;
	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		if (i + 1 >= *n)
		{
			*n *= 2;
			new_ptr = malloc(*n);
			if (new_ptr == NULL)
				return (-1);
			for (j = 0; j < i; j++)
				new_ptr[j] = (*lineptr)[j];
			free(*lineptr);
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = buffer[0];
		if (buffer[0] == '\n')
			break;
	}
	if (bytes_read == -1)
	{
		perror("Error reading input");
		return (-1);
	}
	if (i == 0 && bytes_read == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
