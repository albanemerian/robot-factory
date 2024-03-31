/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** label_checker
*/

#include "../../include/robot.h"

int (*check_label[16])(struct robot_s *, int) = {
    &checker_sti, &checker_ld, &checker_zjmp, &checker_live,
    &checker_add, &checker_st, &checker_sub, &checker_and,
    &checker_or, &checker_xor, &checker_ldi, &checker_fork,
    &checker_ld, &checker_fork, &checker_ldi, &checker_aff};

int handle_label_pointer(robot_t *robot, char *labels[], int index, int i)
{
    if (strcmp_my(robot->array[1], labels[index]) == 1) {
        robot->found_command = 1;
        if ((check_label[index](robot, i)) == 84)
            return 84;
    }
    return 0;
}

int handler(robot_t *robot, char *labels[], int i)
{
    for (int index = 0; index < 16; index++) {
        if (handle_label_pointer(robot, labels, index, i) == 84)
            return 84;
    }
    return 0;
}

int label_checker(robot_t *robot, int i)
{
    char *labels[16] = {"sti", "ld", "zjmp", "live", "add", "st", "sub",
        "and", "or", "xor", "ldi", "fork", "lld", "lfork", "lldi", "aff"};

    robot->label_prog[i] = robot->prog_size;
    if (robot->array[1] != NULL) {
        if (handler(robot, labels, i) == 84)
            return 84;
    }
    if (robot->array[1] == NULL)
        robot->found_command = 1;
    return 0;
}
