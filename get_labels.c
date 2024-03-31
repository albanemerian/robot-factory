/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** get_labels
*/

#include "include/robot.h"

int check_mulitple_label(char **array, FILE *file, robot_t *robot)
{
    for (int f = 0; robot->label[f] != NULL; f++) {
        if (strcmp_my(robot->label[f], array[0]) == 1) {
            write(2, "Multiple definiton of same label\n", 34);
            return 84;
        }
    }
    return 0;
}

int fill_func(int j, char **array, FILE *file, robot_t *robot)
{
    int len = 0;

    len = my_strlen(array[0]);
    if (array[0][len - 1] == ':') {
        if (check_mulitple_label(array, file, robot) == 84)
            return 84;
        robot->label[j] = my_strdup(array[0]);
        robot->len_label[j] = my_strlen(robot->label[j]);
        robot->label_no[j] = my_strndup(array[0], robot->len_label[j] - 1);
        j++;
    }
    return j;
}

int func_fill(int argc, char **argv, FILE *file, robot_t *robot)
{
    char **array = NULL;
    int j = 0;

    robot->label = my_malloc(robot->label, robot->num_label + 1);
    robot->len_label = my_malloc(robot->len_label, robot->num_label + 1);
    robot->label_no = my_malloc(robot->label_no, robot->num_label + 1);
    robot->label_prog = my_malloc(robot->label_prog, robot->num_label + 1);
    while (getline(&robot->l, &robot->len, file) != - 1 ||
        robot->num_label != j) {
        array = my_str_to_word_array(robot->l);
        if (array[0] != NULL)
            j = fill_func(j, array, file, robot);
        if (j == 84)
            return 84;
    }
    return 0;
}

static int label_loop(char **array, int len, robot_t *robot, int i)
{
    for (int j = 0; j <= my_strlen(LABEL_CHARS) - 1; j++) {
        if (LABEL_CHARS[j] == array[0][i]) {
            break;
        }
        if (strcmp_my(&LABEL_CHARS[j], &array[0][i]) != 1 &&
            j == my_strlen(LABEL_CHARS) - 1) {
            write(2, "Incorect label char type\n", 26);
            return 84;
        }
    }
    return 0;
}

static int check_char_in_label_two(char **array, int len, robot_t *robot)
{
    for (int i = 0; i != (len - 1); i++) {
        if (label_loop(array, len, robot, i) == 84)
            return 84;
    }
    return 0;
}

static int check_char_in_label(char **array, int len, robot_t *robot)
{
    if (array[0][len - 1] == ':') {
        robot->num_label++;
        if (check_char_in_label_two(array, len, robot) == 84)
            return 84;
    }
    return 0;
}

int label_count(char **array, int len, robot_t *robot)
{
    if (array[0] != NULL) {
        len = my_strlen(array[0]);
        if (check_char_in_label(array, len, robot) == 84)
            return 84;
    }
    return 0;
}

int count_label(int argc, char **argv, robot_t *robot, header_t *head)
{
    char *fiel = my_strdup(argv[1]);
    FILE *file = fopen(fiel, "r");
    char **array = NULL;
    int len = 0;

    while (getline(&robot->l, &robot->len, file) != -1) {
        array = my_str_to_word_array(robot->l);
        if (label_count(array, len, robot) == 84)
            return 84;
    }
    if (fseek(file, 0, SEEK_SET) != 0) {
        return 84;
    }
    if (robot->num_label != 0) {
        if (func_fill(argc, argv, file, robot) == 84)
            return 84;
        if (check_then_file(argv, argc, robot, head) == 84)
            return 84;
    }
    return 0;
}
