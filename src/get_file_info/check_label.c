/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** check_label
*/

#include "../../include/robot.h"

void (*label[18])(struct robot_s *, FILE *, header_t *) = {
    &name_func, &comment_func, &sti_func, &ld_func,
    &zjmp_func, &live_func, &add_func, &st_func, &sub_func,
    &and_func, &or_func, &xor_func, &ldi_func, &fork_func,
    &lld_func, &lfork_func, &lldi_func, &aff_func};

int handler_info(robot_t *robot, char *flag_label[], FILE *output,
    header_t *head)
{
    for (int index = 0; index < 18; index++) {
        if (strcmp_my(robot->array[1], flag_label[index]) == 1) {
            shift_array(robot->array);
            label[index](robot, output, head);
            break;
        }
    }
    return 0;
}

void label_func(robot_t *robot, FILE *output, header_t *head)
{
    char *flag_label[18] = {".name", ".comment", "sti", "ld", "zjmp",
        "live", "add", "st", "sub", "and", "or", "xor", "ldi", "fork",
        "lld", "lfork", "lldi", "aff"};

    if (robot->array[1] != NULL) {
        if (handler_info(robot, flag_label, output, head) == 84)
            return;
    } else
        return;
}
