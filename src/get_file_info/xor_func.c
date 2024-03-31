/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** xor_func
*/

#include "../../include/robot.h"
static void xor_nine(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 5;
}

static void xor_eigth(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 116, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void xor_seven(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

static void xor_six(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 148, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

static void xor_five(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 180, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

static void xor_four(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 164, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 11;
}

static void xor_three(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 212, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void xor_two(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 244, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 7;
}

static void xor_one(robot_t *robot, FILE *output)
{
    const unsigned char XOR = 0x08;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&XOR, sizeof(XOR), 1, output);
    write_int(output, 228, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

void xor_func(robot_t *robot, FILE *output, header_t *head)
{
    get_xor_size_input(robot);
    if (robot->xor_status == 1)
        xor_one(robot, output);
    if (robot->xor_status == 2)
        xor_two(robot, output);
    if (robot->xor_status == 3)
        xor_three(robot, output);
    if (robot->xor_status == 4)
        xor_four(robot, output);
    if (robot->xor_status == 5)
        xor_five(robot, output);
    if (robot->xor_status == 6)
        xor_six(robot, output);
    if (robot->xor_status == 7)
        xor_seven(robot, output);
    if (robot->xor_status == 8)
        xor_eigth(robot, output);
    if (robot->xor_status == 9)
        xor_nine(robot, output);
}
