/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** func_lldi
*/

#include "../../include/robot.h"

static void lldi_seven(robot_t *robot, FILE *output)
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

void lldi_eigth(robot_t *robot, FILE *output)
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

void lldi_nine(robot_t *robot, FILE *output)
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

void lldi_ten(robot_t *robot, FILE *output)
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

void lldi_eleven(robot_t *robot, FILE *output)
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

void func_lldi(robot_t *robot, FILE *output)
{
    if (robot->ldi_status == 7)
        lldi_seven(robot, output);
    if (robot->ldi_status == 8)
        lldi_eigth(robot, output);
    if (robot->ldi_status == 9)
        lldi_nine(robot, output);
    if (robot->ldi_status == 10)
        lldi_ten(robot, output);
    if (robot->ldi_status == 11)
        lldi_eleven(robot, output);
    if (robot->ldi_status == 12)
        lldi_twelve(robot, output);
    if (robot->ldi_status == 13)
        lldi_thirteen(robot, output);
}
