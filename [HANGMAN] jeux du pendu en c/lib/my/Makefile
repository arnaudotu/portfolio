##
## EPITECH PROJECT, 2022
## task01
## File description:
## makefile
##


SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

.c.o:
	gcc -I./ -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp ./lib.h ../../include/

clean:
	rm -f *.o
	rm -f *~
	rm -f '#'*'#'
	rm -f \*.o

fclean: clean
	rm -f ./$(NAME)

re : fclean all

auteur:
	echo $(USER) > auteur
