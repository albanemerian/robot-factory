/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** check_isnum
*/

#include "../../include/robot.h"

int is_sixteen(char *num)
{
    int number = my_getnbr(num);

    if (number > 0 && number <= 16)
        return 1;
    else
        return 0;
}

int num(char *num)
{
    if (num[0] == '-') {
        num++;
    }
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] < '0' || num[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int num_zero(char *num)
{
    if (num[0] == '-') {
        num++;
    }
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] < '0' || num[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_empty_or_whitespace(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *str = NULL;
    size_t len = 0;
    int i = 0;

    if (file == NULL) {
        return 1;
    }
    while (getline(&str, &len, file) != -1) {
        if (str[i] != ' ' && str[i] != '\n' &&
            str[i] != '\0') {
            fseek(file, 0, SEEK_SET);
            return 0;
        }
        i++;
    }
    fclose(file);
    return 1;
}
