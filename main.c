#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, int fd);
int main(void)
{
	ssize_t line_read;
	char *lineptr;
	size_t len;

	lineptr = NULL;
	len = 0;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line_read = _getline(&lineptr, &len, 0);
		if (line_read == -1)
			break;
		write(STDOUT_FILENO, lineptr, line_read);
	}
	free(lineptr);
	return (0);
}
