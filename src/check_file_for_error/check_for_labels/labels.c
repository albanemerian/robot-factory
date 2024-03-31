/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** labels
*/

#include "../../../include/robot.h"

int checker_zjmp(robot_t *robot, int i)
{
    if (robot->array[3] != NULL) {
        if (robot->array[3][0] != '#') {
            write(2, "To many arguments\n", 19);
            return 84;
        }
    }
    if (robot->array[2] == NULL) {
        return 84;
    }
    for (int j = 0; robot->label_no[j] != NULL; j++) {
        if (strcmp_my(&robot->array[2][2], robot->label_no[j]) == 1 ||
            (robot->array[2][0] == '%' && num_zero(&robot->array[2][1]) == 1))
            break;
        if (strcmp_my(&robot->array[2][2], robot->label_no[j]) != 1 &&
            j == (robot->num_label - 1)) {
            return 84;
        }
    }
    robot->prog_size += 3;
    return 0;
}

int checker_live(robot_t *robot, int i)
{
    if (robot->array[2] == NULL) {
        write(2, "Incorrect live value\n", 22);
        return 84;
    }
    if (robot->array[3] != NULL) {
        if (robot->array[3][0] != '#')
            return 84;
    }
    if (robot->array[2][0] != '%' || num(&robot->array[2][1]) != 1) {
        write(2, "Incorrect live value\n", 22);
        return 84;
    }
    robot->prog_size += 5;
    return 0;
}
