/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** ldi_checker
*/

#include "../../include/robot.h"

int bytes(robot_t *robot, char *str)
{
    int al = 0;

    if (robot->label == NULL) {
        write(2, "Empty label cannot identify it\n", 32);
        return 84;
    }
    for (int j = 0; robot->label_no[j] != NULL || al != 1; j++) {
        if ((robot->label_no != NULL && strcmp_my(str,
            robot->label_no[j]) != 1) && j == (robot->num_label - 1)) {
            write(2, "Incorrect label value\n", 23);
            return 84;
        }
        if ((robot->label_no != NULL && strcmp_my(str,
            robot->label_no[j]) == 1)) {
            al = 1;
            break;
        }
    }
    return 0;
}

static int ldi_checker_part_six(robot_t *robot)
{
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        bytes(robot, &robot->array[1][2]) != 84 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == ':' && bytes(robot,
        &robot->array[1][1]) != 84 && robot->array[2][0] == '%' &&
        num(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    } else {
        write(2, "Incorrect ldi parrameters\n", 27);
        return 84;
    }
}

static int ldi_checker_part_five(robot_t *robot)
{
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_six(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_four(robot_t *robot)
{
    if (num(&robot->array[1][0]) == 1 && robot->array[1][1] == '\0' &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        bytes(robot, &robot->array[1][2]) != 84 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[1][0] == ':' && bytes(robot, &robot->array[1][1]) != 84 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_five(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_three(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[1][1] == '\0' &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (ldi_checker_part_four(robot) == 84)
        return 84;
    return 0;
}

static int ldi_checker_part_two(robot_t *robot)
{
    if (num(&robot->array[1][0]) == 1 && robot->array[1][1] == '\0' &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 6;
        return 0;
    }
    if (ldi_checker_part_three(robot) == 84)
        return 84;
    return 0;
}

int ldi_checker(robot_t *robot)
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
    if (robot->array[3][0] != 'r' || is_sixteen(&robot->array[3][1]) != 1) {
        write(2, "Incorrect register value\n", 26);
        return 84;
    }
    if (ldi_checker_part_two(robot) == 84)
        return 84;
    get_ldi_size_input(robot);
    return 0;
}
