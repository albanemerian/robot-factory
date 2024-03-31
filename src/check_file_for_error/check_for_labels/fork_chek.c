/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** fork_chek
*/

#include "../../../include/robot.h"


int fork_label_lab(robot_t *robot)
{
    int al = 0;

    for (int i = 0; robot->label_no[i] != NULL || al != 1; i++) {
        if (strcmp_my(&robot->array[2][2], robot->label_no[i]) != 1 &&
            i == (robot->num_label - 1)) {
            write(2, "Incorrect label specified\n", 27);
            return 84;
        }
        if (strcmp_my(&robot->array[2][2], robot->label_no[i]) == 1) {
            al = 1;
            break;
        }
    }
    return 0;
}

int checker_fork(robot_t *robot, int i)
{
    if (robot->label_no == NULL) {
        write(2, "The label specified isn't correct\n", 35);
        return 84;
    }
    if (robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1) {
        robot->prog_size += 3;
        return 0;
    }
    if (robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        fork_label_lab(robot) != 84) {
        robot->prog_size += 3;
        return 0;
    } else {
        write(2, "In correct fork paremeter\n", 27);
        return 84;
    }
}
