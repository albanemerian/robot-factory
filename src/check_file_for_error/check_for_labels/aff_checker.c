/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** aff_checker
*/

#include "../../../include/robot.h"

int checker_aff(robot_t *robot, int i)
{
    if (robot->array[3] != NULL) {
        if (robot->array[3][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL || robot->array[2][0] != 'r' ||
        is_sixteen(&robot->array[2][1]) != 1 || robot->array[2][2] != '\0') {
        write(2, "Incorrect aff value\n", 21);
        return 84;
    }
    robot->prog_size += 3;
    return 0;
}
