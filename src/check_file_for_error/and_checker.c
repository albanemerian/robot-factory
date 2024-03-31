/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** pointer_four
*/

#include "../../include/robot.h"

static int and_checker_four(robot_t *robot)
{
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == '%' &&
        num(&robot->array[2][1]) == 1) {
        robot->prog_size += 9;
        return 0;
    }
    if (num(&robot->array[1][0]) == 1 && num(&robot->array[2][0]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r' &&
        is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    write(2, "Incorrect and value\n", 21);
    return 84;
}

static int and_checker_three(robot_t *robot)
{
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 11;
        return 0;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1) {
        robot->prog_size += 9;
        return 0;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 8;
        return 0;
    }
    if (and_checker_four(robot) == 84)
        return 84;
    return 0;
}

int and_checker_two(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 8;
        return 0;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (and_checker_three(robot) == 84)
        return 84;
    return 0;
}

int and_checker(robot_t *robot)
{
    if (robot->array[4] != NULL) {
        if (robot->array[4][0] != '#')
            return 84;
    }
    if (robot->array[1] == NULL || robot->array[2] == NULL ||
        robot->array[3] == NULL || robot->array[3][0] != 'r' ||
        is_sixteen(&robot->array[3][1]) != 1) {
        write(2, "Insufficiant and value\n", 24);
        return 84;
    }
    if (and_checker_two(robot) == 84)
        return 84;
    get_prog_size_input(robot);
    return 0;
}
