#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

ssize_t _getline(char **lineptr, size_t *n, int fd);
int _strcmp(char *str1, char *str2);
char *_strncpy(char *dest, char *src, size_t n);
char **_strtok(char *str, const char *delim);
int _loop(char *str, const char *delim);
void free_words(char **arr);
int _env(char **arr);
void *_malloc(char **lineptr, size_t *n);

#endif
