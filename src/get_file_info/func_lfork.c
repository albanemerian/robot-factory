/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** func_lfork
*/

#include "../../include/robot.h"

void lfork_two(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;

    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 3;
}

void lfork_one(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);

    write_int(output, arg1, 2);
    robot->func_prog += 3;
}

void lfork_func(robot_t *robot, FILE *output, header_t *head)
{
    int stat = fork_stat(robot);
    const unsigned char LFORK = 0x0F;

    fwrite(&LFORK, sizeof(LFORK), 1, output);
    if (stat == 1)
        lfork_one(robot, output);
    if (stat == 2)
        lfork_two(robot, output);
}
