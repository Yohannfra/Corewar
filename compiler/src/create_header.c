/*
** EPITECH PROJECT, 2019
** create_header.c
** File description:
** creates the header
*/

#include "my.h"
#include "asm.h"
#include "op.h"

// #define NAME_CMD_STRING         ".name"
// #define COMMENT_CMD_STRING      ".comment"

header_t *create_header(int fd)
{
    header_t *header = malloc(sizeof(header_t));
    char *str;

    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    str = get_next_instruction(fd);
    str[my_strlen(str) - 1] = 0;
    my_strcpy(header->prog_name, &str[7]);
    free(str);
    str = get_next_instruction(fd);
    str[my_strlen(str) - 1] = 0;
    my_strcpy(header->comment, &str[10]);
    free(str);
    return header;
}
