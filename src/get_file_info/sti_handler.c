/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** sti_handler
*/


#include "../../include/robot.h"

static void sti_six(robot_t *robot, FILE *output)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    write_int(output, 88, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, arg3, 2);
    robot->func_prog += 6;
}

static void sti_five(robot_t *robot, FILE *output)
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

static void sti_four(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 6;
}

static void sti_three(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 116, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][1]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 1);
    robot->func_prog += 6;
}

static void sti_two(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 120, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][1]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 2);
    robot->func_prog += 7;
}

static void sti_one(robot_t *robot, FILE *output)
{
    int j = 0;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int byte_moving = 0;
    int arg2 = my_getnbr(&robot->array[3][1]);

    write_int(output, 104, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][2]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    write_int(output, arg2, 2);
    robot->func_prog += 7;
}

void sti_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char STI = 0x0b;

    prog_size_sti(robot);
    fwrite(&STI, sizeof(STI), 1, output);
    if (robot->sti_tatus == 1)
        sti_one(robot, output);
    if (robot->sti_tatus == 2)
        sti_two(robot, output);
    if (robot->sti_tatus == 3)
        sti_three(robot, output);
    if (robot->sti_tatus == 4)
        sti_four(robot, output);
    if (robot->sti_tatus == 5)
        sti_five(robot, output);
    if (robot->sti_tatus == 6)
        sti_six(robot, output);
    else
        sti_func_part_two(robot, output, head);
}
