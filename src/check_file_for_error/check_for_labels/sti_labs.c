/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** sti_labs
*/

#include "../../../include/robot.h"

static int sti_checker_part_seven(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == '%' && robot->array[4][1] == ':' &&
        bytes(robot, &robot->array[4][2]) != 84){
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84) {
        robot->prog_size += 7;
        return 0;
    } else {
        write(2, "Incorrect sti instruction\n", 27);
        return 84;
    }
}

static int sti_checker_part_six(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        num(&robot->array[3][0]) == 1 && robot->array[4][0] == '%' &&
        robot->array[4][1] == ':' && bytes(robot, &robot->array[4][2]) != 84){
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == '%' && robot->array[4][1] == ':' &&
        bytes(robot, &robot->array[4][2]) != 84){
        robot->prog_size += 7;
        return 0;
    }
    if (sti_checker_part_seven(robot) == 84)
        return 84;
    return 0;
}

static int sti_checker_part_five(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        num(&robot->array[3][0]) == 1 && robot->array[4][0] == '%' &&
        num(&robot->array[4][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        num(&robot->array[3][0]) == 1 && robot->array[4][0] == 'r' &&
        is_sixteen(&robot->array[4][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (sti_checker_part_six(robot) == 84)
        return 84;
    return 0;
}

static int sti_checker_part_four(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == 'r' && is_sixteen(&robot->array[4][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == '%' && num(&robot->array[4][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (sti_checker_part_five(robot) == 84)
        return 84;
    return 0;
}

static int sti_checker_part_three(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == 'r' && is_sixteen(&robot->array[4][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1 &&
        robot->array[4][0] == '%' && num(&robot->array[4][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (sti_checker_part_four(robot) == 84)
        return 84;
    return 0;
}

static int sti_checker_part_two(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == ':' && bytes(robot, &robot->array[3][1]) != 84 &&
        robot->array[4][0] == 'r' && is_sixteen(&robot->array[4][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84 && robot->array[4][0] ==
        'r' && is_sixteen(&robot->array[4][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (sti_checker_part_three(robot) == 84)
        return 84;
    return 0;
}

static int sti_checker_two(robot_t *robot)
{
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84 && robot->array[4][0] ==
        '%' && num(&robot->array[4][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == ':' && bytes(robot, &robot->array[3][1])
        != 84 && robot->array[4][0] == '%' && num(&robot->array[4][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (sti_checker_part_two(robot) == 84)
        return 84;
    return 0;
}

int checker_sti(robot_t *robot, int i)
{
    if (robot->array[5] != NULL) {
        if (robot->array[5][0] != '#')
            return 84;
    }
    if (robot->array[2][0] != 'r' || is_sixteen(&robot->array[2][1]) != 1 ||
        robot->array[3] == NULL || robot->array[4] == NULL) {
        write(2, "Incorrect sti value\n", 21);
        return 84;
    }
    if (sti_checker_two(robot) == 84)
        return 84;
    return 0;
}
