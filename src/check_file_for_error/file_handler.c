/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** file_handler
*/

#include "../include/robot.h"

int check_then_file(char **argv, int argc, robot_t *robot,
    header_t *head)
{
    robot->and_status = 0;
    robot->or_status = 0;
    if (check_file(argc, argv, robot) == 84)
        return 84;
    else
        get_info_from_file(robot, head, argv);
    return 0;
}
