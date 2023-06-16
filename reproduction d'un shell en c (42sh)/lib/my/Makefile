##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	$(wildcard *.c)

HEADERS		=	includes.h				\
				h_headers.h				\
				h_lib.h					\
				h_lists.h				\
				h_macros.h				\
				h_types.h				\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CC			=	gcc

$(NAME):	all

all:		compile

compile:	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(HEADERS) ../../includes/lib/
	@cp $(NAME) ../
	@echo "\033[32mLib compiled !\033[0m"

clean:
	@rm -f *.swp
	@rm -rf $(OBJ)
	@echo "\033[31mLib cleaned\033[0m"

fclean:		clean
	@rm -rf ../../includes/lib/*
	@rm -rf ../$(NAME)
	@rm -rf $(NAME)
	@echo "\033[31mLib purged\033[0m"

re:			fclean	compile
