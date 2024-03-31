/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** sti_size
*/

#include "../../include/robot.h"

static void prog_size_part_six(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84)
        robot->sti_tatus = 14;
}

void prog_size_part_five(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84){
        robot->sti_tatus = 12;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && robot->array[3][1] == ':' &&
        bytes(robot, &robot->array[3][2]) != 84){
        robot->sti_tatus = 13;
    } else
        prog_size_part_six(robot);
}

void prog_size_part_four(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1 && robot->array[3][0] == 'r' &&
        num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 10;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1 && robot->array[3][0] == '%' &&
        robot->array[3][1] == ':' && bytes(robot, &robot->array[3][2]) != 84){
        robot->sti_tatus = 11;
    } else
        prog_size_part_five(robot);
}

void prog_size_part_three(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 7;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 8;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        num(&robot->array[2][0]) == 1 && robot->array[3][0] == '%' &&
        num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 9;
    } else
        prog_size_part_four(robot);
}

void prog_size_part_two(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 && robot->array[3][0] ==
        'r' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 4;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == 'r' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 5;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == 'r' && num(&robot->array[2][1]) == 1 &&
        robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 6;
    } else
        prog_size_part_three(robot);
}

void prog_size_sti(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == '%' && robot->array[2][1] == ':' &&
        bytes(robot, &robot->array[2][2]) != 84 && robot->array[3][0] ==
        '%' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 1;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == ':' && bytes(robot, &robot->array[2][1])
        != 84 && robot->array[3][0] == '%' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 2;
    }
    if (robot->array[1][0] == 'r' && num(&robot->array[1][1]) == 1 &&
        robot->array[2][0] == ':' && bytes(robot, &robot->array[2][1])
        != 84 && robot->array[3][0] == 'r' && num(&robot->array[3][1]) == 1) {
        robot->sti_tatus = 3;
    } else
        prog_size_part_two(robot);
}
