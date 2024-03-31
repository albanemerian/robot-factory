/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** pointer
*/

#include "../../include/robot.h"

static int zjmp_checker_two(robot_t *robot)
{
    if (robot->label_no == NULL)
        return 84;
    for (int j = 0; robot->label_no[j] != NULL; j++) {
        if (strcmp_my(&robot->array[1][2], robot->label_no[j]) == 1 ||
            (robot->array[1][0] == '%' && num_zero(&robot->array[1][1]) == 1))
            break;
        if (strcmp_my(&robot->array[1][2], robot->label_no[j]) != 1 &&
            j == (robot->num_label - 1)) {
            write(2, "Incorrect zjmp value\n", 22);
            return 84;
        }
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1)
        robot->zjmp_stat = 1;
    else
        robot->zjmp_stat = 2;
    return 0;
}

int zjmp_checker(robot_t *robot)
{
    if (robot->array[2] != NULL) {
        if (robot->array[2][0] != '#') {
            return 84;
        }
    }
    if (robot->array[1] == NULL) {
        write(2, "Incorrect zjmp value\n", 22);
        return 84;
    }
    if (robot->array[1][0] == '%' && num_zero(&robot->array[1][1]) == 1) {
        robot->zjmp_stat = 1;
        robot->prog_size += 3;
        return 0;
    }
    if (zjmp_checker_two(robot) == 84)
        return 84;
    robot->prog_size += 3;
    return 0;
}

int live_checker(robot_t *robot)
{
    if (robot->array[1] == NULL) {
        write(2, "Incorrect live value\n", 22);
        return 84;
    }
    if (robot->array[2] != NULL) {
        if (robot->array[2][0] != '#')
            return 84;
    }
    if (robot->array[1][0] != '%' || num(&robot->array[1][1]) != 1) {
        write(2, "Incorrect live value\n", 22);
        return 84;
    }
    robot->prog_size += 5;
    return 0;
}
