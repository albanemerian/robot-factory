/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** aff_checker
*/

#include "../../include/robot.h"

int aff_checker(robot_t *robot)
{
    if (robot->array[2] != NULL) {
        if (robot->array[2][0] != '#')
            return 84;
    }
    if (robot->array[1] == NULL || robot->array[1][0] != 'r' ||
        is_sixteen(&robot->array[1][1]) != 1) {
        write(2, "Incorrect aff value\n", 21);
        return 84;
    }
    robot->prog_size += 3;
    return 0;
}
