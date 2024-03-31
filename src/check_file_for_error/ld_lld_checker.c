/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** ld_lld_checker
*/

#include "../../include/robot.h"


static int check_label(robot_t *robot)
{
    int al = 0;

    if (robot->label_no == NULL)
        return 84;
    for (int i = 0; robot->label_no != NULL || al != 1; i++) {
        if (strcmp_my(robot->label_no[i], &robot->array[1][2]) == 1){
            al = 1;
            break;
        }
        if (strcmp_my(robot->label_no[i], &robot->array[1][2]) != 1 &&
            i == (robot->num_label - 1))
            return 84;
    }
    return 0;
}

int part_two_ld(robot_t *robot)
{
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        check_label(robot) != 84 && robot->array[2][0] == 'r' &&
        is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    } else {
        write(2, "Incorrect ld value\n", 20);
        return 84;
    }
}

int ld_checker(robot_t *robot)
{
    if (robot->array[1] == NULL || robot->array[2] == NULL) {
        write(2, "Incorrect ld value\n", 20);
        return 84;
    }
    if (robot->array[3] != NULL) {
        if (robot->array[3][0] != '#')
            return 84;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r' &&
        is_sixteen(&robot->array[2][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (part_two_ld(robot) == 84)
        return 84;
    return 0;
}
