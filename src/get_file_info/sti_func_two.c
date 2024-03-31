/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** sti_func_two
*/

#include "../../include/robot.h"

static void sti_fourteen(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int i = 0;
    int res1 = 0;
    int res2 = 0;

    write_int(output, 104, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[i], &robot->array[2][2]) != 1; i++);
    res1 = robot->label_prog[i] - robot->func_prog;
    write_int(output, res1, 2);
    i = 0;
    for (; strcmp_my(robot->label_no[i], &robot->array[3][2]) != 1; i++);
    res2 = robot->label_prog[i] - robot->func_prog;
    write_int(output, res2, 2);
    robot->func_prog += 7;
}

static void sti_thirteen(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int byte_moving = 0;
    int j = 0;

    write_int(output, 88, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[3][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 6;
}

static void sti_twelve(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int byte_moving = 0;
    int j = 0;

    write_int(output, 104, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    for (; strcmp_my(robot->label_no[j], &robot->array[3][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 7;
}

static void sti_eleven(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int byte_moving = 0;
    int j = 0;

    write_int(output, 120, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    for (; strcmp_my(robot->label_no[j], &robot->array[3][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 7;
}

static void sti_ten(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 116, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void sti_nine(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 120, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 2);
    robot->func_prog += 7;
}

static void sti_eigth(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 104, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 2);
    robot->func_prog += 7;
}

static void sti_seven(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

void sti_func_part_two(robot_t *robot, FILE *output, header_t *head)
{
    if (robot->sti_tatus == 7)
        sti_seven(robot, output);
    if (robot->sti_tatus == 8)
        sti_eigth(robot, output);
    if (robot->sti_tatus == 9)
        sti_nine(robot, output);
    if (robot->sti_tatus == 10)
        sti_ten(robot, output);
    if (robot->sti_tatus == 11)
        sti_eleven(robot, output);
    if (robot->sti_tatus == 12)
        sti_twelve(robot, output);
    if (robot->sti_tatus == 13)
        sti_thirteen(robot, output);
    if (robot->sti_tatus == 14)
        sti_fourteen(robot, output);
}
