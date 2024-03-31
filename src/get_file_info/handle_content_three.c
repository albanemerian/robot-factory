/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** handle_content_three
*/

#include "../../include/robot.h"


void sub_func(robot_t *robot, FILE *output, header_t *head)
{
    int arg1 = 0;
    int arg2 = 0;
    int total = 0;
    const unsigned char SUB = 0x05;

    fwrite(&SUB, sizeof(SUB), 1, output);
    arg1 = my_getnbr(&robot->array[1][1]);
    arg2 = my_getnbr(&robot->array[2][1]);
    total = my_getnbr(&robot->array[3][1]);
    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, total, 1);
    robot->func_prog += 5;
}

static void get_st_stat(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == ':' && bytes(robot, &robot->array[2][1]) != 84) {
        robot->st_stat = 1;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        num(robot->array[2]) == 1) {
        robot->st_stat = 2;
    }
    if (robot->array[1][0] == 'r' && is_sixteen(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1) {
        robot->st_stat = 3;
    }
}

static void st_part_three(FILE *output, robot_t *robot)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(&robot->array[2][1]);

    write_int(output, 80, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    robot->func_prog += 4;
    return;
}

static void st_part_two(FILE *output, robot_t *robot)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int arg2 = my_getnbr(robot->array[2]);

    write_int(output, 112, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 2);
    robot->func_prog += 5;
    return;
}

static void st_part_one(FILE *output, robot_t *robot)
{
    int arg1 = my_getnbr(&robot->array[1][1]);
    int j = 0;
    int byte_moving = 0;

    write_int(output, 112, 1);
    write_int(output, arg1, 1);
    for (; strcmp_my(robot->label_no[j], &robot->array[2][1]) != 1; j++);
    byte_moving = robot->label_prog[j] - robot->func_prog;
    write_int(output, byte_moving, 2);
    robot->func_prog += 5;
    return;
}

void st_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char ST = 0x03;

    get_st_stat(robot);
    fwrite(&ST, sizeof(ST), 1, output);
    if (robot->st_stat == 1)
        st_part_one(output, robot);
    if (robot->st_stat == 2)
        st_part_two(output, robot);
    if (robot->st_stat == 3)
        st_part_three(output, robot);
}

void add_func(robot_t *robot, FILE *output, header_t *head)
{
    int arg1 = 0;
    int arg2 = 0;
    int total = 0;
    const unsigned char ADD = 0x04;

    fwrite(&ADD, sizeof(ADD), 1, output);
    arg1 = my_getnbr(&robot->array[1][1]);
    arg2 = my_getnbr(&robot->array[2][1]);
    total = my_getnbr(&robot->array[3][1]);
    write_int(output, 84, 1);
    write_int(output, arg1, 1);
    write_int(output, arg2, 1);
    write_int(output, total, 1);
    robot->func_prog += 5;
}
