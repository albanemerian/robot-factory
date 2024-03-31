/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** main
*/

#include "include/robot.h"

static int no_label_loop(int argc, char **argv, robot_t *robot, header_t *head)
{
    if (check_then_file(argv, argc, robot, head) == 84)
        return 84;
    return 0;
}

int get_label(char **argv, robot_t *robot, header_t *head, int argc)
{
    char *fiel = my_strdup(argv[1]);
    FILE *file = fopen(fiel, "r");

    if (count_label(argc, argv, robot, head) == 84)
        return 84;
    fclose(file);
    if (robot->num_label == 0) {
        if (no_label_loop(argc, argv, robot, head) == 84)
            return 84;
    } else
        return 0;
    return 0;
}

int main_two(int argc, char **argv, robot_t *robot, header_t *head)
{
    if (strcmp_my(argv[1], "-h") == 1 || strcmp_my(argv[1], "--help") == 1) {
        helper(argv);
        return 0;
    }
    if (get_label(argv, robot, head, argc) == 84) {
        return 84;
    }
    return 0;
}

static int error_handling(int argc, char **argv, struct stat *file_stat)
{
    char *file = 0;

    if (argc < 2 || argc > 2) {
        print("Not enough arguments check the helper (-h or --help)\n");
        return 84;
    }
    file = my_strdup(argv[1]);
    if (stat(argv[1], file_stat) != 0) {
        print("Error: File '%s' not found.\n", argv[1]);
        return 84;
    }
    if (file_stat->st_size == 0 || is_empty_or_whitespace(file) == 1) {
        print("Error: File '%s' is empty or contains only whitespace");
        print(" characters.\n");
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    robot_t *robot = 0;
    header_t *head = 0;
    struct stat file_stat;

    if (error_handling(argc, argv, &file_stat) == 84)
        return 84;
    head = (header_t *)my_malloc(head, sizeof(header_t));
    robot = (robot_t *)my_malloc(robot, sizeof(robot_t));
    robot->num_label = 0;
    if (main_two(argc, argv, robot, head) == 84)
        return 84;
    return 0;
}
