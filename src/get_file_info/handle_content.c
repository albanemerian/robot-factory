/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** handle_content
*/

#include "../include/robot.h"


void write_int(FILE *output, int num, int size)
{
    unsigned char byte = 0;

    for (int i = size - 1; i >= 0; i--) {
        byte = (num >> (i * 8)) & 0xFF;
        fwrite(&byte, sizeof(unsigned char), 1, output);
    }
}

void live_func(robot_t *robot, FILE *output, header_t *head)
{
    int live = 0;
    const unsigned char LIVE = 0x01;
    char *res = NULL;

    res = remove_modulo(robot->array[1]);
    live = my_getnbr(res);
    fwrite(&LIVE, sizeof(LIVE), 1, output);
    write_int(output, live, 4);
    robot->func_prog += 5;
}

void zjmp_func(robot_t *robot, FILE *output, header_t *head)
{
    int j = 0;
    const unsigned char ZJMP = 0x09;
    int res = 0;

    if (robot->array[1][0] == '%' && num(&robot->array[1][1]) == 1)
        robot->zjmp_stat = 1;
    else
        robot->zjmp_stat = 2;
    fwrite(&ZJMP, sizeof(ZJMP), 1, output);
    if (robot->zjmp_stat == 2) {
        for (; strcmp_my(robot->label_no[j], &robot->array[1][2]) != 1; j++);
        res = robot->label_prog[j] - robot->func_prog;
        write_int(output, res, 2);
        robot->func_prog += 3;
    }
    if (robot->zjmp_stat == 1) {
        res = my_getnbr(&robot->array[1][1]);
        write_int(output, res, 2);
        robot->func_prog += 3;
    }
}
