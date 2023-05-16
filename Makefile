##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for the project minishell / CPE semestre 2
##


POL 		= src/pol/
GREG		= src/greg/
TERMIOS		= $(POL)termios/
GROF		= $(POL)grof/

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

BIN 		= 42sh

SRCFILES	= \
		based_function/my_put_nbr.c								\
		based_function/my_putstr.c								\
		based_function/my_putchar.c								\
		based_function/my_strlen.c								\
		based_function/my_str_to_word_array.c					\
		based_function/my_strcat.c								\
		based_function/my_strcmp.c								\
		based_function/my_strcpy.c								\
		based_function/my_strdup.c								\
		based_function/my_strmerge.c							\
		based_function/my_strncmp.c								\
		based_function/my_strndup.c								\
		src/main.c												\
		src/sub_main.c											\
		src/infinite_loop.c										\
		src/detect_signal.c										\
		src/execution.c											\
		src/errno.c												\
		src/binary_tree/binary_tree.c							\
		src/binary_tree/parseur_function.c						\
		\
		src/binary_operator/pipe.c								\
		src/binary_operator/redirection.c						\
		src/binary_operator/double_redirection_left.c					\
		src/binary_operator/formatting_str_for_redirection_left.c			\
		src/binary_operator/separator.c							\
		src/binary_operator/double_pipe.c						\
		src/binary_operator/double_esperluette.c				\
		src/binary_operator/look_backsticks.c					\
		src/binary_operator/backst.c						\
		src/binary_operator/globbing.c						\
\
		$(POL)line_formating.c\
		$(POL)env.c\
		$(POL)string.c\
		$(POL)aliases.c\
		$(POL)custom.c\
		$(POL)unalias.c\
		$(POL)file_manip.c\
		$(POL)history.c\
		$(POL)setups.c\
		$(POL)misc.c\
		$(POL)classic_input.c\
		$(POL)replace_variable.c\
		\
		$(TERMIOS)termios_arrows.c\
		$(TERMIOS)termios_getinput.c\
		$(TERMIOS)termios_input.c\
		$(TERMIOS)termios_tab.c\
		$(TERMIOS)termios_history.c\
		$(TERMIOS)termios_history_ncommand.c\
		\
		$(GROF)grof.c\
		$(GROF)grof_variable_creation.c\
		$(GROF)grof_type.c\
		$(GROF)grof_process.c\
		$(GROF)grof_arithmetics.c\
		$(GROF)grof_function.c\
		$(GROF)grof_builtins.c\
		$(GROF)grof_tabpos.c\
		$(GROF)grof_operations.c\
		$(GROF)grof_operations_usefull.c\
		$(GROF)grof_for_loop.c\
		$(GROF)grof_variable.c\
		\
		$(GREG)echo.c\
		$(GREG)echo_flag.c\
		$(GREG)pause.c

SRC_TEST	=	based_function/my_put_nbr.c	\
                based_function/my_putstr.c	\
                based_function/my_putchar.c	\
                based_function/my_strlen.c	\
                based_function/my_strcat.c	\
                based_function/my_strcmp.c	\
                based_function/my_strcpy.c	\
                based_function/my_strdup.c	\
                based_function/my_strmerge.c	\
                based_function/my_strncmp.c	\
                based_function/my_strndup.c	\

TRC	=	tests/test.c

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

CC			?= gcc

SRCOBJ      = $(SRCFILES:.c=.o)
CFLAGS		= -Wall -Wextra -g3
CPPFLAGS	= -iquote ./include
CFLAGS_CRITERION	=	--coverage -lcriterion

LIBDIR		= ./lib
LDFLAGS		= -L./$(LIBDIR)
LDLIBS		= -lmy

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

all: 		$(BIN)

$(BIN): 	$(SRCOBJ)
			@if [ -n "$(filter -g3,$(CFLAGS))" ]; then \
				make -C $(LIBDIR) debug; \
			else \
				make -C $(LIBDIR); \
			fi
			$(CC) $(SRCOBJ) $(LDFLAGS) $(LDLIBS) -o $(BIN)

clean:
	make -C $(LIBDIR) clean
	$(RM) $(SRCOBJ)

fclean:	clean
	make -C $(LIBDIR) fclean
	$(RM) $(BIN)
	$(RM) *.gc*

build_tests:	fclean
		$(CC) -o build_tests $(TRC) $(SRC_TEST) $(CPPFLAGS) $(CFLAGS_CRITERION)

tests_run:	build_tests
		./build_tests

re:		fclean all

redebug:	fclean debug

debug:		CFLAGS += -g3
debug:		$(BIN)

pol:		redebug
			@make clean
			make -C $(LIBDIR) fclean

.PHONY:		all fclean clean build_tests tests_run re redebug debug pol

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
