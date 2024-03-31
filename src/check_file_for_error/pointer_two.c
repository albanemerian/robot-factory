/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** pointer_two
*/

#include "../../include/robot.h"

static int comment_check_two(robot_t *robot, int c, int j)
{
    if (robot->comment_defined == 1) {
        write(2, "Comment can only be defined once\n", 34);
        return 84;
    }
    if (j >= 2062) {
        write(2, "Comment is to long\n", 20);
        return 84;
    }
    if (robot->array[1] == NULL || c != 2) {
        return 84;
    }
    if (robot->name_stat != 1) {
        write(2, "The comment must be after the name\n", 36);
        return 84;
    }
    return 0;
}

static int counter(robot_t *robot, int c, int i)
{
    if (c == 2) {
        if (robot->l[i + 1] != ' ' && robot->l[i + 1] != '\n' &&
            robot->l[i + 1] != '\0') {
            write(2, "Syntax error\n", 14);
            return 84;
        }
    }
    return i;
}

int comment_checker(robot_t *robot)
{
    int c = 0;
    int j = 0;

    for (int i = 0; robot->l[i] != '\0'; i++) {
        j++;
        if (robot->l[i] == '"')
            c++;
        if (counter(robot, c, i) == 84)
            return 84;
    }
    if (comment_check_two(robot, c, j) == 84)
        return 84;
    else {
        robot->comment_defined = 1;
        robot->comment_stat = 1;
        return 0;
    }
    return 0;
}

static int name_checker_two(robot_t *robot, int c, int j)
{
    if (robot->name_defined == 1) {
        write(2, "Multiple definitions of name\n", 30);
        return 84;
    }
    if (j >= 139) {
        write(2, "Name is too long\n", 18);
        return 84;
    }
    if (robot->array[1] == NULL || c != 2) {
        write(2, "Incorrect Name\n", 16);
        return 84;
    }
    return 0;
}

int name_checker(robot_t *robot)
{
    int c = 0;
    int j = 0;

    for (int i = 0; robot->l[i] != '\0'; i++) {
        j++;
        if (robot->l[i] == '"')
            c++;
        if (counter(robot, c, i) == 84)
            return 84;
    }
    if (name_checker_two(robot, c, j) == 84)
        return 84;
    else {
        robot->name_stat = 1;
        robot->name_defined = 1;
        return 0;
    }
    return 0;
}
