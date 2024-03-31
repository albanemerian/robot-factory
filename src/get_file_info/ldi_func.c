/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** ldi_func
*/

#include "../../include/robot.h"

void ldi_thirteen(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg1 = my_getnbr(&robot->array[2][1]);
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 228, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][1]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

void ldi_twelve(robot_t *robot, FILE *output)
{
    int byte_moving = 0;
    int j = 0;
    int arg1 = my_getnbr(&robot->array[2][1]);
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 164, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 7;
}

static void ldi_six(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 5;
}

static void ldi_five(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 212, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void ldi_four(robot_t *robot, FILE *output)
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

static void ldi_three(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 148, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void ldi_two(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 164, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 7;
}

static void ldi_one(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 228, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 7;
}

void ldi_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char LDI = 0x0a;

    get_ldi_size_input(robot);
    fwrite(&LDI, sizeof(LDI), 1, output);
    if (robot->ldi_status == 1)
        ldi_one(robot, output);
    if (robot->ldi_status == 2)
        ldi_two(robot, output);
    if (robot->ldi_status == 3)
        ldi_three(robot, output);
    if (robot->ldi_status == 4)
        ldi_four(robot, output);
    if (robot->ldi_status == 5)
        ldi_five(robot, output);
    if (robot->ldi_status == 6)
        ldi_six(robot, output);
    else
        func_ldi(robot, output);
}
