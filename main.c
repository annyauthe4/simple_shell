#include "main.h"

/**
  * main - Function execution starts from here
  *
  * Return: 0 on success
  */
ssize_t _getline(char **lineptr, size_t *n, int fd);
int main(void)
{
	ssize_t line_read;
	char *lineptr, *ext;
	size_t len;

	ext = "exit\n";
	lineptr = NULL;
	len = 0;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line_read = _getline(&lineptr, &len, 0);
		if (line_read == -1)
			break;
		if (_strcmp(ext, lineptr) == 0)
			exit(0);
		write(STDOUT_FILENO, lineptr, line_read);
	}
	free(lineptr);
	return (0);
}

/**
  * _strcmp - Compares two strings and returns the difference
  * @str1: String to compare
  * @str2: String to compare
  *
  * Return: 0 if strings are the same or the difference
  */
int _strcmp(char *str1, char *str2)
{
	int i, diff;

	i = 0;
	diff = 0;
	while (1)
	{
		diff = str1[i] - str2[i];
		if (diff != 0 || str1[i] == '\0' || str2[i] == '\0')
		{
			break;
		}
		i++;
	}
	return (diff);
}
