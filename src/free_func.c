/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** free_func
*/

#include "../include/robot.h"

void free_func(robot_t *robot)
{
    for (int i = 0; robot->array[i] != NULL; i++) {
        free(robot->array[i]);
    }
    free(robot->array);
    free(robot);
}
