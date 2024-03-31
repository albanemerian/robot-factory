/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** ldi_checker
*/

#include "../../../include/robot.h"

static int ldi_checker_part_six_label(robot_t *robot)
{
    if (robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == ':' && bytes(robot,
        &robot->array[2][1]) != 84 && robot->array[3][0] == '%' &&
        num(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    } else {
        write(2, "Incorrect ldi parrameters\n", 27);
        return 84;
    }
}

static int ldi_checker_part_five_label(robot_t *robot)
{
    if (robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_six_label(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_four_label(robot_t *robot)
{
    if (num(&robot->array[2][0]) == 1 && robot->array[2][1] == '\0' &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[2][0] == ':' && bytes(robot, &robot->array[2][1]) != 84 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_five_label(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_three_label(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (num(&robot->array[2][0]) == 1 && robot->array[2][1] == '\0' &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (ldi_checker_part_four_label(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_two_label(robot_t *robot)
{
    if (num(&robot->array[2][0]) == 1 && robot->array[2][1] == '\0' &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_three_label(robot) == 84)
        return 84;
    return 0;
}

int checker_ldi(robot_t *robot, int i)
{
    if (robot->array[5] != NULL) {
        if (robot->array[5][0] != '#')
            return 84;
    }
    if (robot->array[2] == NULL ||
        robot->array[3] == NULL || robot->array[4] == NULL) {
        write(2, "Insufficiant or value\n", 23);
        return 84;
    }
    if (robot->array[4][0] != 'r' || is_sixteen(&robot->array[4][1]) != 1) {
        write(2, "Incorrect register value\n", 26);
        return 84;
    }
    if (ldi_checker_part_two_label(robot) == 84)
        return 84;
    get_ldi_size_input(robot);
    return 0;
}
