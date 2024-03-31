/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** get_ldi_stat
*/

#include "../../include/robot.h"

static void ldi_size_ldi(robot_t *robot)
{
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        robot->array[2][0] == '%' && robot->array[2][1] != ':') {
        robot->ldi_status = 12;
    }
    if (robot->array[1][0] == ':' && robot->array[2][0] == '%') {
        robot->ldi_status = 13;
    }
}

void size_ldi(robot_t *robot)
{
    if (robot->array[1][0] == '%' && robot->array[1][1] == ':' &&
        robot->array[2][0] == 'r') {
        robot->ldi_status = 8;
    }
    if (robot->array[1][0] == ':' && robot->array[2][0] == 'r') {
        robot->ldi_status = 9;
    }
    if (robot->array[1][0] == '%' && robot->array[2][0] == '%' &&
        robot->array[2][1] == ':') {
        robot->ldi_status = 10;
    }
    if (robot->array[1][0] == 'r' && robot->array[2][0] == '%' &&
        robot->array[2][1] == ':') {
        robot->ldi_status = 11;
    } else
        ldi_size_ldi(robot);
}

void ldi_size(robot_t *robot)
{
    if (robot->array[1][0] == 'r' && robot->array[2][0] == '%' &&
        robot->array[2][1] != ':') {
        robot->ldi_status = 4;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == 'r') {
        robot->ldi_status = 5;
    }
    if (robot->array[1][0] == 'r' && robot->array[2][0] == 'r') {
        robot->ldi_status = 6;
    }
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == '%' &&
        robot->array[2][1] == ':') {
        robot->ldi_status = 7;
    } else
        size_ldi(robot);
}

void get_ldi_size_input(robot_t *robot)
{
    if (num(&robot->array[1][0]) == 1 && robot->array[2][0] == '%' &&
        robot->array[2][1] != ':') {
        robot->ldi_status = 1;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] != ':' &&
        robot->array[2][0] == '%' && robot->array[2][1] != ':') {
        robot->ldi_status = 2;
    }
    if (robot->array[1][0] == '%' && robot->array[1][1] != ':' &&
        robot->array[2][0] == 'r') {
        robot->ldi_status = 3;
    } else
        ldi_size(robot);
}
