/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** error_handling
*/

#include "../../include/robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int (*check_arg[18])(struct robot_s *) = {
    &name_checker, &comment_checker, &sti_checker,
    &ld_checker, &zjmp_checker, &live_checker, &add_checker,
    &st_checker, &sub_checker, &and_checker, &or_checker, &xor_checker,
    &ldi_checker, &fork_checker, &ld_checker, &fork_checker, &ldi_checker,
    &aff_checker};

int handle_pointer(robot_t *robot, char *arg_check[], int index)
{
    if (strcmp_my(robot->array[0], arg_check[index]) == 1) {
        robot->found_command = 1;
        if ((check_arg[index](robot)) == 84)
            return 84;
    }
    return 0;
}

int check_value(robot_t *robot, char **arg_check, char **argv, int argc)
{
    for (int index = 0; index < 18; index++) {
        if (handle_pointer(robot, arg_check, index) == 84)
            return 84;
    }
    if (robot->found_command != 1) {
        write(2, "Invalid instructions\n", 22);
        return 84;
    }
    return 0;
}

static int check_labs_value(robot_t *robot, int argc, char **argv)
{
    for (int i = 0; robot->label[i] != NULL; i++) {
        if (strcmp_my(robot->array[0], robot->label[i]) == 1)
            label_checker(robot, i);
    }
    return 0;
}

static int process_line(robot_t *robot, char *arg_check[], int argc,
    char **argv)
{
    char *dup = NULL;

    if (robot->l[0] == COMMENT_CHAR)
        return 0;
    if (remove_comment(robot->l) == 84)
        return 84;
    dup = my_strdup(robot->l);
    robot->array = my_str_to_word_array(dup);
    if (robot->array[0] != NULL) {
        robot->found_command = 0;
        if (robot->array[0][my_strlen(robot->array[0]) - 1] == ':')
            check_labs_value(robot, argc, argv);
        if (check_value(robot, arg_check, argv, argc) == 84) {
            return 84;
        }
    }
    return 0;
}

int check_file(int argc, char **argv, robot_t *robot)
{
    char *arg_check[18] = {".name", ".comment", "sti", "ld", "zjmp", "live",
        "add", "st", "sub", "and", "or", "xor", "ldi", "fork", "lld", "lfork",
        "lldi", "aff"};
    FILE *file = fopen(argv[1], "r");

    robot->prog_size = 0;
    while (getline(&robot->l, &robot->len, file) != -1) {
        if (process_line(robot, arg_check, argc, argv) == 84) {
            fclose(file);
            return 84;
        }
    }
    fclose(file);
    return 0;
}
