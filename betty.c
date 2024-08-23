#include "main.h"

/**
  * main - takes in argument and print it out
  * @argc: argument count
  * @argv: argument vector
  *
  * Return: 0 on success, 1 on failure
  */
int main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (i == 0)
		{
			printf("This program name is %s\n", argv[i]);
		}
		else
		{
			printf("Other arguments are:\n");
			printf("%s\n", argv[i]);
		}
		i++;
	}
	return (0);
}
