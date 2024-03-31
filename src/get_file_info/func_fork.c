/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** fork_checker
*/

#include "../../include/robot.h"

int fork_stat(robot_t *robot)
{
    int stat = 0;

    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1) {
        stat = 1;
        return stat;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':') {
        stat = 2;
        return stat;
    }
    return 0;
}

void fork_two(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;

    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 3;
}

void fork_one(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);

    write_int(output, arg1, 2);
    robot->func_prog += 3;
}

void fork_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char FORK = 0x0c;
    int stat = fork_stat(robot);

    fwrite(&FORK, sizeof(FORK), 1, output);
    if (stat == 1)
        fork_one(robot, output);
    if (stat == 2)
        fork_two(robot, output);
}
