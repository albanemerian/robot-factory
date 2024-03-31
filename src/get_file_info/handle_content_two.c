/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** handle_content_two
*/

#include "../../include/robot.h"

static void write_name(robot_t *robot, FILE *output, header_t *head,
    int length)
{
    char null_byte = 0x00;
    const unsigned char NAME = 0x00;

    head->magic = COREWAR_EXEC_MAGIC;
    fwrite(&NAME, sizeof(NAME), 1, output);
    write_int(output, head->magic, 3);
    fwrite(head->prog_name, 1, (length - 1), output);
    for (int j = length; j < PROG_NAME_LENGTH; j++) {
        fwrite(&null_byte, sizeof(char), 1, output);
    }
}

void name_func(robot_t *robot, FILE *output, header_t *head)
{
    char *res = NULL;
    int length = 0;
    int start_index = 0;
    int end_index = 0;

    while (robot->l[start_index] != '"')
        start_index++;
    end_index = start_index + 1;
    while (robot->l[end_index] != '"' && robot->l[end_index] != '\0')
        end_index++;
    length = end_index + 1 - start_index;
    res = my_strndup(&robot->l[start_index + 1], length);
    my_strcpy(head->prog_name, remove_cotes(res));
    length = my_strlen(head->prog_name);
    write_name(robot, output, head, length);
}

static void write_comment(robot_t *robot, FILE *output, header_t *head,
    int length)
{
    char null_byte = 0x00;
    const unsigned char COMMENT = 0x00;

    fwrite(&COMMENT, sizeof(unsigned char), 1, output);
    write_int(output, head->prog_size, 3);
    fwrite(head->comment, sizeof(char), (length - 1), output);
    for (int j = (length - 4); j < (COMMENT_LENGTH + 1); j++) {
        fwrite(&null_byte, sizeof(char), 1, output);
    }
}

void comment_func(robot_t *robot, FILE *output, header_t *head)
{
    int length = 0;
    const unsigned char COMMENT = 0x00;
    char *res = NULL;
    int start_index = 0;
    int end_index = 0;

    fwrite(&COMMENT, sizeof(char), 5, output);
    head->prog_size = robot->prog_size;
    while (robot->l[start_index] != '"')
        start_index++;
    end_index = start_index + 1;
    while (robot->l[end_index] != '"' && robot->l[end_index] != '\0')
        end_index++;
    length = end_index + 1 - start_index;
    res = my_strndup(&robot->l[start_index + 1], length);
    my_strcpy(head->comment, remove_cotes(res));
    length = my_strlen(head->comment);
    write_comment(robot, output, head, length);
}

void func_comment(robot_t *robot, FILE *output, header_t *head)
{
    int length = 0;
    char null_byte = 0x00;

    for (int i = 0; i <= 5; i++) {
        fwrite(&null_byte, sizeof(char), 1, output);
    }
    head->prog_size = robot->prog_size;
    write_int(output, head->prog_size, 3);
    for (int j = (length - 4); j < (COMMENT_LENGTH); j++) {
        fwrite(&null_byte, sizeof(char), 1, output);
    }
}
