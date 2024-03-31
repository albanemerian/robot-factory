/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-robotfactory-matisse.marsac
** File description:
** robot
*/

#include "my.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#ifndef ROBOT_H_
    #define ROBOT_H_

typedef struct robot_s {
    char *l;
    size_t len;
    ssize_t read;
    char **array;
    FILE *file;
    char **label;
    char **label_no;
    int found_command;
    int *len_label;
    int prog_size;
    int *label_prog;
    int func_prog;
    int ld_lld;
    int sti_tatus;
    int and_status;
    int or_status;
    int xor_status;
    int ldi_status;
    int name_stat;
    int comment_stat;
    int j;
    int num_label;
    int comment_defined;
    int name_defined;
    int zjmp_stat;
    int st_stat;
}robot_t;


//usage functions
void helper(char **argv);
int check_then_file(char **argv, int argc, robot_t *robot,
    header_t *head);
void write_int(FILE *output, int num, int size);
char *remove_cotes(char *str);
int check_file(int argc, char **argv, robot_t *robot);
void free_func(robot_t *robot);
void get_info_from_file(robot_t *robot, header_t *head, char **argv);
char *remove_first_arg(char *input);
char *remove_modulo(char *str);
char *remove_file_extension(const char *filename);
int remove_comment(char *line);
int num(char *num);
void shift_array(char **array);
int count_label(int argc, char **argv, robot_t *robot, header_t *head);
int bytes(robot_t *robot, char *str);
int is_sixteen(char *num);
int num_zero(char *num);
int is_empty_or_whitespace(const char *filename);

//get size for multiple call
void prog_size_sti(robot_t *robot);
void get_or_size_input(robot_t *robot);
void get_prog_size_input(robot_t *robot);
void get_xor_size_input(robot_t *robot);
void get_ldi_size_input(robot_t *robot);
void ld_lld_stat(robot_t *robot);
int fork_stat(robot_t *robot);
void prog_size_s(robot_t *robot, int i);

//pointer to verify the state of the file;
int name_checker(robot_t *robot);
int comment_checker(robot_t *robot);
int sti_checker(robot_t *robot);
int ld_checker(robot_t *robot);
int live_checker(robot_t *robot);
int zjmp_checker(robot_t *robot);
int add_checker(robot_t *robot);
int st_checker(robot_t *robot);
int sub_checker(robot_t *robot);
int label_checker(robot_t *robot, int i);
int and_checker(robot_t *robot);
int or_checker(robot_t *robot);
int xor_checker(robot_t *robot);
int ldi_checker(robot_t *robot);
int fork_checker(robot_t *robot);
int aff_checker(robot_t *robot);

//pointer to check file if as a label

int checker_sti(robot_t *robot, int i);
int checker_ld(robot_t *robot, int i);
int checker_live(robot_t *robot, int i);
int checker_zjmp(robot_t *robot, int i);
int checker_add(robot_t *robot, int i);
int checker_st(robot_t *robot, int i);
int checker_sub(robot_t *robot, int i);
int checker_and(robot_t *robot, int i);
int checker_or(robot_t *robot, int i);
int checker_xor(robot_t *robot, int i);
int checker_ldi(robot_t *robot, int i);
int checker_fork(robot_t *robot, int i);
int checker_aff(robot_t *robot, int i);

//pointer to get information
void name_func(robot_t *robot, FILE *output, header_t *head);
void comment_func(robot_t *robot, FILE *output, header_t *head);
void func_comment(robot_t *robot, FILE *output, header_t *head);
void sti_func(robot_t *robot, FILE *output, header_t *head);
void sti_func_part_two(robot_t *robot, FILE *output, header_t *head);
void live_func(robot_t *robot, FILE *output, header_t *head);
void ld_func(robot_t *robot, FILE *output, header_t *head);
void zjmp_func(robot_t *robot, FILE *output, header_t *head);
void add_func(robot_t *robot, FILE *output, header_t *head);
void st_func(robot_t *robot, FILE *output, header_t *head);
void sub_func(robot_t *robot, FILE *output, header_t *head);
void label_func(robot_t *robot, FILE *output, header_t *head);
void and_func(robot_t *robot, FILE *output, header_t *head);
void or_func(robot_t *robot, FILE *output, header_t *head);
void xor_func(robot_t *robot, FILE *output, header_t *head);
void ldi_func(robot_t *robot, FILE *output, header_t *head);
void func_ldi(robot_t *robot, FILE *output);
void ldi_eigth(robot_t *robot, FILE *output);
void ldi_nine(robot_t *robot, FILE *output);
void ldi_ten(robot_t *robot, FILE *output);
void ldi_eleven(robot_t *robot, FILE *output);
void ldi_twelve(robot_t *robot, FILE *output);
void ldi_thirteen(robot_t *robot, FILE *output);
void fork_func(robot_t *robot, FILE *output, header_t *head);
void lld_func(robot_t *robot, FILE *output, header_t *head);
void lfork_func(robot_t *robot, FILE *output, header_t *head);
void lldi_func(robot_t *robot, FILE *output, header_t *head);
void func_lldi(robot_t *robot, FILE *output);
void lldi_twelve(robot_t *robot, FILE *output);
void lldi_thirteen(robot_t *robot, FILE *output);
void aff_func(robot_t *robot, FILE *output, header_t *head);
#endif /* !ROBOT_H_ */
