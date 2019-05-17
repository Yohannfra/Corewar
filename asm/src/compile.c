/*
** EPITECH PROJECT, 2019
** compile.c
** File description:
** starts the compilation
*/

#include "asm.h"
#include "my.h"

static void check_info_redef(char *str)
{
    int index = 0;
    char *comment_str = COMMENT_CMD_STRING;

    for (; str[index] && is_one_of_them(str[index], " \t"); index++);
    if (my_strncmp(&str[index], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
        my_error("Name can only be defined once");
    if (my_strncmp(&str[index], comment_str, my_strlen(comment_str)))
        my_error("Comment can only be defined once");
}

void compile(int fd, char *new_file)
{
    char *str;
    header_t *header = my_calloc(sizeof(header_t));
    label_t *label_list = NULL;
    op_list_t *op_list = NULL;

    // printf("\ntotal bytes theorically written: \e[1m\e[32m%d\e[0m (%d)\n", offset_pos(0, GET) + sizeof(header_t), offset_pos(0, GET));
    str = get_name_and_comment(fd, header);
    while (str != NULL) {
        // printf("\ninstruction found: {\e[1m\e[34m%s\e[0m}\n", str);
        check_info_redef(str);
        parse_instruction(str, &label_list, &op_list);
        free(str);
        str = get_next_instruction(fd);
    }
    // printf("\n------------BEGINNING WRITING-----------\n\n");
    write_in_file(header, label_list, op_list, new_file);
}
