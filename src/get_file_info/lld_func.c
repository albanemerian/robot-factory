/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** lld_func
*/

#include "../../include/robot.h"

void lld_three(robot_t *robot, FILE *output)
{
    int j = 0;
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 208, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 4);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

void lld_two(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 208, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

void lld_one(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 208, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 5;
}

void lld_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char LLD = 0x0d;

    ld_lld_stat(robot);
    fwrite(&LLD, sizeof(LLD), 1, output);
    if (robot->ld_lld == 1)
        lld_one(robot, output);
    if (robot->ld_lld == 2)
        lld_two(robot, output);
    if (robot->ld_lld == 3)
        lld_three(robot, output);
}
