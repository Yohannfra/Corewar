/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for asm
*/

#include "my.h"
#include "asm.h"

static void check_args(int ac, char const *av[])
{
    char *help = "USAGE\n\t%s file_name[.s]\n"
    "DESCRIPTION\n\n"
    "\tfile_name\tfile in assembly language "
    "to be converted into file_name.cor, an\n"
    "\t\t\texecutable in the Virtual Machine.\n";

    if (ac != 2 || my_strcmp(av[1], "-h") || my_strcmp(av[1], "--help")) {
        my_printf(help, av[0]);
        exit(84);
    }
}

static char *check_file(char const *file, int *fd)
{
    char *dup;

    *fd = open(file, O_RDONLY);
    if (*fd < 0) {
        my_printf("%s: no such file\n", file);
        return NULL;
    }
    dup = my_strdup(file);
    for (size_t i = my_strlen(dup) - 1; i > 0; i--)
        if (dup[i] == '.')
            dup[i] = '\0';
    return dup;
}

int main(int ac, char const *av[])
{
    char *name = NULL;
    int fd = 0;

    check_args(ac, av);
    name = check_file(av[1], &fd);//changes fd of file to read, return name to compile
    if (name == NULL)
        return 84;
    my_printf("file: {%s}. fd: {%d}. dest: {%s.cor}\n", av[1], fd, name);// ca marche jusqu'ici
    //linter(fd); + lseek
    //compile(fd); read fd, write into "name"
    free(name);
    return 0;
}