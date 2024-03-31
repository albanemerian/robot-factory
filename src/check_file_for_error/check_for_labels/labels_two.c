/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** labels_two
*/

#include "../../../include/robot.h"

int checker_sub(robot_t *robot, int i)
{
    if (robot->array[5] != NULL) {
        if (robot->array[5][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL ||
        robot->array[3] == NULL || robot->array[4] == NULL) {
        write(2, "Insufficiant sub value\n", 24);
        return 84;
    }
    if (robot->array[2][0] != 'r' || is_sixteen(&robot->array[2][1]) != 1 ||
        robot->array[3][0] != 'r' || is_sixteen(&robot->array[3][1]) != 1 ||
        robot->array[4][0] != 'r' || is_sixteen(&robot->array[4][1]) != 1) {
        write(2, "Incorrect sub value\n", 21);
        return 84;
    }
    robot->prog_size += 5;
    return 0;
}

static int checker_st_part_with(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        num(robot->array[3]) == 1) {
        robot->st_stat = 2;
        robot->prog_size += 5;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && num(&robot->array[3][1]) == 1) {
        robot->st_stat = 3;
        robot->prog_size += 4;
        return 0;
    }
    write(2, "Incorrect st value\n", 20);
    return 84;
}

int checker_st(robot_t *robot, int i)
{
    if (robot->array[4] != NULL) {
        if (robot->array[4][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL || robot->array[3] == NULL) {
        write(2, "Insufficiant st value\n", 23);
        return 84;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == ':' && bytes(robot, &robot->array[3][1]) != 84) {
        robot->st_stat = 1;
        robot->prog_size += 5;
        return 0;
    }
    if (checker_st_part_with(robot) == 84)
        return 84;
    return 0;
}

int checker_add(robot_t *robot, int i)
{
    if (robot->array[5] != NULL) {
        if (robot->array[4][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL ||
        robot->array[3] == NULL || robot->array[3] == NULL) {
        write(2, "Insufficiant add value\n", 24);
        return 84;
    }
    if (robot->array[2][0] != 'r' || is_sixteen(&robot->array[2][1]) != 1 ||
        robot->array[3][0] != 'r' || is_sixteen(&robot->array[3][1]) != 1 ||
        robot->array[4][0] != 'r' || is_sixteen(&robot->array[4][1]) != 1) {
        write(2, "Incorrect add value\n", 21);
        return 84;
    }
    robot->prog_size += 5;
    return 0;
}
