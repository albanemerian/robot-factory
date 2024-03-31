/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** func_ldi
*/

#include "../../include/robot.h"

static void ldi_seven(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(robot->array[1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 228, 1);
    write_int(output, arg1, 2);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

void ldi_eigth(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg1 = my_getnbr(&robot->array[2][1]);
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 148, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    robot->func_prog += 6;
}

void ldi_nine(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg1 = my_getnbr(&robot->array[2][1]);
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 212, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][1]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    robot->func_prog += 6;
}

void ldi_ten(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 164, 1);
    write_int(output, arg1, 2);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

void ldi_eleven(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 6;
}

void func_ldi(robot_t *robot, FILE *output)
{
    if (robot->ldi_status == 7)
        ldi_seven(robot, output);
    if (robot->ldi_status == 8)
        ldi_eigth(robot, output);
    if (robot->ldi_status == 9)
        ldi_nine(robot, output);
    if (robot->ldi_status == 10)
        ldi_ten(robot, output);
    if (robot->ldi_status == 11)
        ldi_eleven(robot, output);
    if (robot->ldi_status == 12)
        ldi_twelve(robot, output);
    if (robot->ldi_status == 13)
        ldi_thirteen(robot, output);
}
