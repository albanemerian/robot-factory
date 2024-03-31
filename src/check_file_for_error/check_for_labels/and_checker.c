/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** and_checker
*/

#include "../../../include/robot.h"


void get_prog_size_input_part(robot_t *robot)
{
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1)
        robot->and_status = 5;
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1)
        robot->and_status = 6;
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == '%' &&
        num(&robot->array[2][1]) == 1)
        robot->and_status = 7;
    if (num(&robot->array[1][0]) == 1 && num(&robot->array[2][0]) == 1)
        robot->and_status = 8;
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r' &&
        num(&robot->array[2][1]) == 1)
        robot->and_status = 9;
}

void get_prog_size(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1)
        robot->and_status = 1;
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1)
        robot->and_status = 2;
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1)
        robot->and_status = 3;
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1)
        robot->and_status = 4;
    else
        get_prog_size_input_part(robot);
}

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

int checker_and_two(robot_t *robot)
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

int checker_and(robot_t *robot, int i)
{
    if (robot->array[5] != NULL) {
        if (robot->array[5][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL ||
        robot->array[3] == NULL || robot->array[4] == NULL) {
        write(2, "Insufficiant and value\n", 24);
        return 84;
    }
    if (checker_and_two(robot) == 84)
        return 84;
    get_prog_size(robot);
    return 0;
}
