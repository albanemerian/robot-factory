/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** remove_cotes
*/

#include "../include/robot.h"


char *remove_file_extension(const char *filename)
{
    int len = my_strlen(filename);
    int dot_index = -1;
    char *result = NULL;

    for (int i = len - 1; i >= 0; i--) {
        if (filename[i] == '.') {
            dot_index = i;
            break;
        }
    }
    if (dot_index == -1) {
        return my_strdup(filename);
    }
    result = (char *)malloc(dot_index + 1);
    if (result == NULL) {
        return NULL;
    }
    my_strncpy(result, filename, dot_index);
    result[dot_index] = '\0';
    return result;
}

char *remove_first_arg(char *input)
{
    char *space_ptr = NULL;
    int i = 0;

    for (; input[i] == ' '; i++);
    space_ptr = my_strstr(&input[i], " ");
    if (space_ptr == NULL) {
        return my_strdup(input);
    }
    return my_strdup(space_ptr + 1);
}

static void cotes_remove(char *dest, const char *str)
{
    while (*str != '\0') {
        if (*str != '\"') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';
}

char *remove_cotes(char *str)
{
    size_t len = 0;
    const char *ptr = my_strdup(str);
    char *result = NULL;

    while (*ptr != '\0') {
        if (*ptr != '\"') {
            len++;
        }
        ptr++;
    }
    result = (char *)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    cotes_remove(result, str);
    return result;
}

static void modulo_remove(char *dest, const char *str)
{
    while (*str != '\0') {
        if (*str != '%') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';
}

char *remove_modulo(char *str)
{
    size_t len = 0;
    const char *ptr = my_strdup(str);
    char *result = NULL;

    while (*ptr != '\0') {
        if (*ptr != '%') {
            len++;
        }
        ptr++;
    }
    result = (char *)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    modulo_remove(result, str);
    return result;
}

int remove_comment(char *line)
{
    char *comment_pos = my_strstr(line, "#");

    if (comment_pos != NULL) {
        if (line[1] == '#') {
            write(2, "Comment should be after variable\n", 34);
            return 84;
        } else
            *comment_pos = '\0';
    }
    return 0;
}
