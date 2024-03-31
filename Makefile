##
## EPITECH PROJECT, 2023
## my_organize
## File description:
## my_organize
##

CC	=	gcc

NAME	=	asm

UNIT_TEST	= test

CFLAGS	=	-Wshadow -Werror -Wall -I./include

CRITFLAG	=	tests/test_lib.c tests/test_orga.c --coverage -lcriterion

LIBS	=	-L./ -lmy

TEST_LIBS	=	-L./ -lmy

SRC		=   main.c										\
			get_labels.c									\
			src/helper.c								\
			src/free_func.c								\
			src/change_array_order.c					\
			src/get_file_info/remove_cotes.c			\
			src/get_file_info/handle_content.c			\
			src/get_file_info/handle_content_two.c		\
			src/get_file_info/handle_content_three.c	\
			src/get_file_info/check_label.c				\
			src/get_file_info/get_info.c				\
			src/get_file_info/and_func.c				\
			src/get_file_info/sti_handler.c				\
			src/get_file_info/sti_func_two.c			\
			src/get_file_info/sti_size.c				\
			src/get_file_info/or_func.c					\
			src/get_file_info/xor_func.c				\
			src/get_file_info/ldi_func.c				\
			src/get_file_info/func_ldi.c				\
			src/get_file_info/lldi_func.c				\
			src/get_file_info/func_lldi.c				\
			src/get_file_info/func_fork.c				\
			src/get_file_info/func_lfork.c				\
			src/get_file_info/ld_func.c					\
			src/get_file_info/lld_func.c				\
			src/get_file_info/aff_func.c				\
			src/get_file_info/get_and_stat.c				\
			src/check_file_for_error/error_handling.c	\
			src/check_file_for_error/pointer.c			\
			src/check_file_for_error/pointer_two.c		\
			src/check_file_for_error/file_handler.c		\
			src/check_file_for_error/pointer_three.c	\
			src/check_file_for_error/and_checker.c		\
			src/check_file_for_error/or_checker.c		\
			src/check_file_for_error/sti_checker.c		\
			src/check_file_for_error/xor_handler.c		\
			src/check_file_for_error/ld_lld_checker.c	\
			src/check_file_for_error/ldi_checker.c		\
			src/check_file_for_error/aff_checker.c		\
			src/check_file_for_error/get_ldi_stat.c		\
			src/check_file_for_error/fork_checker.c		\
			src/check_file_for_error/label_checker.c	\
			src/check_file_for_error/check_isnum.c		\
			src/check_file_for_error/check_for_labels/labels.c	\
			src/check_file_for_error/check_for_labels/labels_two.c	\
			src/check_file_for_error/check_for_labels/sti_labs.c	\
			src/check_file_for_error/check_for_labels/and_checker.c	\
			src/check_file_for_error/check_for_labels/or_checker.c	\
			src/check_file_for_error/check_for_labels/xor_checks.c	\
			src/check_file_for_error/check_for_labels/ldi_checker.c	\
			src/check_file_for_error/check_for_labels/ld_lld_checks.c	\
			src/check_file_for_error/check_for_labels/fork_chek.c		\
			src/check_file_for_error/check_for_labels/aff_checker.c

SRCTEST	=

OBJ		=	$(SRC:.c=.o)

all:	libmy $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

$(UNIT_TEST): libmy
			$(CC) -o $(UNIT_TEST) $(SRCTEST) $(CRITFLAG) $(TEST_LIBS)

tests_run:	$(UNIT_TEST)
			@./$(UNIT_TEST)
			@gcovr --exclude tests/

.PHONY: libmy

libmy:
	$(MAKE) -C lib/my

norm:
	@make clean
	@make fclean
	@coding-style . .
	@cat coding-style-reports.log

clean:
			$(MAKE) -C lib/my clean
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f libmy.a

fclean:	clean
			$(MAKE) -C lib/my fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"
			@rm -f libmy.a
			@rm -f *.cor

re:	fclean all
