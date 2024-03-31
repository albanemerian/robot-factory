/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** or_func
*/

#include "../../include/robot.h"

static void or_one(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 5;
}

static void or_two(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

static void or_three(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][0]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 116, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void or_four(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 148, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

static void or_five(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 164, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 11;
}

static void or_six(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][0]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 180, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

static void or_seven(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][0]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 212, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void or_eigth(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][0]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 228, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

static void or_nine(robot_t *robot, FILE *output)
{
    const unsigned char OR = 0x07;
    int arg1 = my_getnbr(&robot->array[1][0]);
    int arg2 = my_getnbr(&robot->array[2][0]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&OR, sizeof(OR), 1, output);
    write_int(output, 244, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 7;
}

void or_func(robot_t *robot, FILE *output, header_t *head)
{
    get_or_size_input(robot);
    if (robot->or_status == 1)
        or_one(robot, output);
    if (robot->or_status == 2)
        or_two(robot, output);
    if (robot->or_status == 3)
        or_three(robot, output);
    if (robot->or_status == 4)
        or_four(robot, output);
    if (robot->or_status == 5)
        or_five(robot, output);
    if (robot->or_status == 6)
        or_six(robot, output);
    if (robot->or_status == 7)
        or_seven(robot, output);
    if (robot->or_status == 8)
        or_eigth(robot, output);
    if (robot->or_status == 9)
        or_nine(robot, output);
}
