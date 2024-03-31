/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** and_func
*/

#include "../../include/robot.h"

static void and_nein(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 212, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void and_eigth(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 244, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 7;
}

static void and_seven(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(robot->array[1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 228, 1);
    write_int(output, arg1, 2);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

static void and_six(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 148, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

static void and_five(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 180, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 9;
}

static void and_four(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 164, 1);
    write_int(output, arg1, 4);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 11;
}

static void and_three(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, arg3, 1);
    robot->func_prog += 5;
}

static void and_two(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 116, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    write_int(output, arg3, 1);
    robot->func_prog += 6;
}

static void and_one(robot_t *robot, FILE *output)
{
    const unsigned char AND = 0x06;
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);
    int arg3 = my_getnbr(&robot->array[3][1]);

    fwrite(&AND, sizeof(AND), 1, output);
    write_int(output, 100, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 4);
    write_int(output, arg3, 1);
    robot->func_prog += 8;
}

void and_func(robot_t *robot, FILE *output, header_t *head)
{
    get_prog_size_input(robot);
    if (robot->and_status == 1)
        and_one(robot, output);
    if (robot->and_status == 2)
        and_two(robot, output);
    if (robot->and_status == 3)
        and_three(robot, output);
    if (robot->and_status == 4)
        and_four(robot, output);
    if (robot->and_status == 5)
        and_five(robot, output);
    if (robot->and_status == 6)
        and_six(robot, output);
    if (robot->and_status == 7)
        and_seven(robot, output);
    if (robot->and_status == 8)
        and_eigth(robot, output);
    if (robot->and_status == 9)
        and_nein(robot, output);
}
