/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** aff_func
*/

#include "../../include/robot.h"

void aff_func(robot_t *robot, FILE *output, header_t *head)
{
    const unsigned char AFF = 0x10;
    int arg1 = my_getnbr(&robot->array[1][1]);

    fwrite(&AFF, sizeof(AFF), 1, output);
    write_int(output, 64, 1);
    write_int(output, arg1, 1);
    robot->func_prog += 3;
}
