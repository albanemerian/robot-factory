/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** get_and_stat
*/

#include "../../include/robot.h"

void get_prog_size_input_part_two(robot_t *robot)
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

void get_prog_size_input(robot_t *robot)
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
        get_prog_size_input_part_two(robot);
}
