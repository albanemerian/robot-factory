/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** lld_stat
*/

#include "../../include/robot.h"

void ld_lld_stat(robot_t *robot)
{
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r' &&
        num(&robot->array[2][1]) == 1) {
        robot->ld_lld = 1;
    }
    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1) {
        robot->ld_lld = 2;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1) {
        robot->ld_lld = 3;
    }
}

static void ld_three(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 144, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 4);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

static void ld_two(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 144, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

static void ld_one(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 208, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 5;
}

void ld_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char LD = 0x02;

    ld_lld_stat(robot);
    fwrite(&LD, sizeof(LD), 1, output);
    if (robot->ld_lld == 1)
        ld_one(robot, output);
    if (robot->ld_lld == 2)
        ld_two(robot, output);
    if (robot->ld_lld == 3)
        ld_three(robot, output);
}
