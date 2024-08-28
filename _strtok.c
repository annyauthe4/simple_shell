#include "main.h"

/**
  * _strncpy - Copies n bytes of string
  * @dest: destination space
  * @src: source string
  * @n: number of bytes to copy
  *
  * Return: a pointer to a string
  */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
/**
  * _loop - Loops through the word
  * @str: an array of strings
  * @delim: The delimeter of each word
  *
  * Return: number of word count
  */
int _loop(char *str, const char *delim)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == *delim)
			str++;
		if (*str)
			count++;
		while (*str && *str != *delim)
			str++;
	}
	return (count);
}
/**
  * _strtok - Splits the line into an array of strings
  * @str: Pointer to the line of strings
  * @delim: Delimeter(separator) of each string
  *
  * Return: pointer to an array of strings
  */
char **_strtok(char *str, const char *delim)
{
	char *tmp, *start;
	int count, i;
	char **arr;
	size_t word_len;

	tmp = str;
	count = 0, i = 0;
	arr = NULL;
	count = _loop(tmp, delim);
	arr = malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
	{
		perror("Malloc error\n");
		exit(1);
	}
	word_len = 0;
	while (*tmp)
	{
		while (*tmp == *delim)
			tmp++;
		if (*tmp)
		{
			start = tmp;
			while (*tmp && *tmp != *delim)
				tmp++;
			word_len = tmp - start;
			arr[i] = malloc(word_len + 1);
			if (arr[i] == NULL)
			{
				perror("Word malloc error\n");
				free_words(arr);
				exit(1);
			}
			_strncpy(arr[i], start, word_len);
			arr[i][word_len] = '\0';
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
