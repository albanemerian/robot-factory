/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** ldi_ldi_checks
*/

#include "../../../include/robot.h"

static int check_label_lab(robot_t *robot)
{
    int al = 0;

    for (int i = 0; robot->label_no != NULL || al != 1; i++) {
        if (strcmp_my(robot->label_no[i], &robot->array[2][2]) == 1){
            al = 1;
            break;
        }
        if (strcmp_my(robot->label_no[i], &robot->array[2][2]) != 1 &&
            i == (robot->num_label - 1))
            return 84;
    }
    return 0;
}

int part_two_ld_lab(robot_t *robot)
{
    if (robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    }
    if (robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        check_label_lab(robot) != 84 && robot->array[3][0] == 'r' &&
        is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 7;
        return 0;
    } else {
        write(2, "Incorrect ld value\n", 20);
        return 84;
    }
}

int checker_ld(robot_t *robot, int i)
{
    if (robot->array[2] == NULL || robot->array[3] == NULL) {
        write(2, "Incorrect ld value\n", 20);
        return 84;
    }
    if (robot->array[4] != NULL) {
        if (robot->array[4][0] != '#')
            return 84;
    }
    if (num(&robot->array[2][0]) == 1 && robot->array[3][0] == 'r' &&
        is_sixteen(&robot->array[3][1]) == 1) {
        robot->prog_size += 5;
        return 0;
    }
    if (part_two_ld_lab(robot) == 84)
        return 84;
    return 0;
}
