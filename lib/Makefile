##
## EPITECH PROJECT, 2023
## lib2
## File description:
## Makefile
##

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

LSTR	= my_string/
LUNI	= my_unistd/
LARR	= my_stdarray/
LEPI	= my_epilib/
LSLI	= my_stdlib/
LSIO	= my_stdio/

LIBFILES 	= \
			$(LSTR)my_addchars.c\
			$(LSTR)my_memory.c\
			$(LSTR)my_newstr.c\
			$(LSTR)my_strcase.c\
			$(LSTR)my_strcats.c\
			$(LSTR)my_strclean.c\
			$(LSTR)my_strcmp.c\
			$(LSTR)my_strcpy.c\
			$(LSTR)my_strcut.c\
			$(LSTR)my_strlen.c\
			$(LSTR)my_strnorm.c\
			$(LSTR)my_strrev.c\
			$(LSTR)my_strsplit.c\
			$(LSTR)my_strstrs.c\
			\
			$(LARR)my_arrayadd.c\
			$(LARR)my_arrayfree.c\
			$(LARR)my_arraylen.c\
			$(LARR)my_arraypop.c\
			$(LARR)my_newarray.c\
			$(LARR)my_arrayvisual.c\
			$(LARR)my_arrayindex.c\
			$(LARR)my_arraycat.c\
			\
			$(LSLI)my_atof.c\
			$(LSLI)my_atoi.c\
			$(LSLI)my_ftoa.c\
			$(LSLI)my_isit.c\
			$(LSLI)my_itoa.c\
			$(LSLI)my_ctoa.c\
			$(LSLI)my_math.c\
			\
			$(LSIO)my_serial.c\
			$(LSIO)my_parser.c\
			$(LSIO)my_getchar.c\
			$(LSIO)my_scanf.c\
			$(LSIO)my_printf.c\
			$(LSIO)my_putstr.c\

CC			?= gcc
AR			= ar rc
RM			= rm -f

LIBOBJ      = $(LIBFILES:.c=.o)
CFLAGS		= -Wall -Wextra
BIN 		= libmy.a

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

all: 		$(BIN)

$(BIN): 	$(LIBOBJ)
			$(AR) $(BIN) $(LIBOBJ)

clean:
			$(RM) $(LIBOBJ)

fclean:		clean
			$(RM) $(BIN)

debug:		CFLAGS += -g3
debug:		$(BIN)

re:			fclean all
			@make clean

.PHONY:		all fclean clean re debug

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
