#include "main.h"

/**
  * free_words - Frees allocated arrays of memory
  * @arr: Arrays of memories
  *
  * Return: void
  */
void free_words(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
/**
  * main - Function execution starts from here
  *
  * Return: 0 on success
  */
int main(void)
{
	ssize_t line_read;
	char *linept, *ext;
	size_t len;

	ext = "exit\n";
	linept = NULL;
	len = 0;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line_read = _getline(&linept, &len, 0);
		if (line_read == -1)
			break;
		if (_strcmp(ext, linept) == 0)
			exit(0);
		write(STDOUT_FILENO, linept, line_read);
	}
	free(linept);
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
