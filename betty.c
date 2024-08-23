#include "main.h"

/**
  * main - Prints out a message
  *
  * Return: 0 on success, 1 on failure
  */
int main(void)
{
	char *message;

	message = "I love C as it makes me dogged\n";
	write(STDOUT_FILENO, message, 32);
	return (0);
}
