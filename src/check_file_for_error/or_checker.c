/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** or_checker
*/

#include "../../include/robot.h"

void or_size(robot_t *robot)
{
    if (robot->array[1][0] == '%' && robot->array[2][0] == '%') {
        robot->prog_size += 11;
        robot->or_status = 5;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[2][0]) == 1) {
        robot->prog_size += 9;
        robot->or_status = 6;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r') {
        robot->prog_size += 6;
        robot->or_status = 7;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == '%') {
        robot->prog_size += 9;
        robot->or_status = 8;
    }
    if (num(&robot->array[1][0]) == 1 && num(&robot->array[2][0]) == 1) {
        robot->prog_size += 7;
        robot->or_status = 9;
    }
}

void get_or_size_input(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && robot->array[2][0] == 'r') {
        robot->prog_size += 5;
        robot->or_status = 1;
    }
    if (robot->array[1][0] == 'r' && robot->array[2][0] == '%') {
        robot->prog_size += 8;
        robot->or_status = 2;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[2][0]) == 1) {
        robot->prog_size += 6;
        robot->or_status = 3;
    }
    if (robot->array[1][0] == '%' && robot->array[2][0] == 'r') {
        robot->prog_size += 8;
        robot->or_status = 4;
    } else
        or_size(robot);
}

int or_checker_two(robot_t *robot)
{
    if (((robot->array[1][0] != 'r' || is_sixteen(&robot->array[1][1]) != 1) &&
        (robot->array[1][0] != '%' || num(&robot->array[1][1]) != 1) &&
        num(&robot->array[1][0]) != 1)) {
        write(2, "Incorrect or value\n", 20);
        return 84;
    }
    if (((robot->array[2][0] != '%' || num(&robot->array[2][1]) != 1) &&
        (robot->array[2][0] != 'r' || is_sixteen(&robot->array[2][1]) != 1) &&
        num(&robot->array[2][0]) != 1)) {
        write(2, "Incorrect or 2 value\n", 22);
        return 84;
    }
    if (robot->array[3][0] != 'r' || is_sixteen(&robot->array[3][1]) != 1) {
        write(2, "Incorrect or 3 value\n", 22);
        return 84;
    }
    return 0;
}

int or_checker(robot_t *robot)
{
    if (robot->array[4] != NULL) {
        if (robot->array[4][0] != '#')
            return 84;
    }
    if (robot->array[1] == NULL ||
        robot->array[2] == NULL || robot->array[3] == NULL) {
        write(2, "Insufficiant or value\n", 23);
        return 84;
    }
    if (or_checker_two(robot) == 84)
        return 84;
    get_or_size_input(robot);
    return 0;
}
