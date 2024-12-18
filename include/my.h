/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** lib prototypes
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <stdbool.h>

int my_getnbr(char const *str);

int my_strlen(char const *str);
int my_tablen(char const **tab);

void my_printf(const char *str, ...);
void my_putchar(char c);
int my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *my_strndup(char const *src);
char *my_strcat(char *buffer, char *str);

bool my_str_isnum(char const *str);
bool is_one_of_them(char c, char const *str);

bool my_strcmp(char const *s1, char const *s2);
bool my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp_diff(char const *s1, char const *s2);

void *my_calloc(size_t size);

char *get_next_line(int fd);
char **my_str_delim_array(char const *str, char const *delims);

int line_counter(int status);

void my_error(const char *error_fmt);
void my_error_str(const char *error_fmt, const char *error_str);

#endif /* MY_H_ */
