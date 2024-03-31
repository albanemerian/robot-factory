/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** change_array_order
*/

#include "../include/robot.h"

void shift_array(char **array)
{
    int i = 1;

    for (; array[i] != NULL; i++) {
        array[i - 1] = array[i];
    }
    array[i - 1] = NULL;
}
