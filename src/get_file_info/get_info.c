/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** get_info
*/

#include "../../include/robot.h"

void (*fm[18])(struct robot_s *, FILE *, header_t *) = {
    &name_func, &comment_func, &sti_func, &ld_func,
    &zjmp_func, &live_func, &add_func, &st_func, &sub_func, &and_func,
    &or_func, &xor_func, &ldi_func, &fork_func, &lld_func, &lfork_func,
    &lldi_func, &aff_func};


void check_pointer(robot_t *robot, char **flag_m, FILE *output, header_t *head)
{
    for (int index = 0; index < 18; index++) {
        if (strcmp_my(robot->array[0], flag_m[index]) == 1) {
            fm[index](robot, output, head);
            break;
        }
        if (index == 1 && robot->comment_stat != 1 && robot->j == 0) {
            func_comment(robot, output, head);
            robot->j = 1;
        }
    }
}

static void from_file_info(robot_t *robot, header_t *head, FILE *output,
    char *flag_m[])
{
    if (robot->array[0] != NULL) {
        if (robot->array[0][strlen(robot->array[0]) - 1] == ':')
            label_func(robot, output, head);
        else
            check_pointer(robot, flag_m, output, head);
    }
}

void get_info_from_file(robot_t *robot, header_t *head, char **argv)
{
    char *flag_m[18] = {".name", ".comment", "sti", "ld", "zjmp",
        "live", "add", "st", "sub", "and", "or", "xor", "ldi", "fork", "lld",
        "lfork", "lldi", "aff"};
    char *fun = remove_file_extension(argv[1]);
    char const *filename = my_strcat(fun, ".cor");
    FILE *output = fopen(filename, "w");
    FILE *file = fopen(argv[1], "r");

    robot->j = 0;
    for (int i = 0; robot->array[i] != NULL; i++)
        free(robot->array[i]);
    free(robot->array);
    while (getline(&robot->l, &robot->len, file) != -1) {
        remove_comment(robot->l);
        robot->array = my_str_to_word_array(robot->l);
        from_file_info(robot, head, output, flag_m);
    }
}
