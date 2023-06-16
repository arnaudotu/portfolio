##
## EPITECH PROJECT, 2022
## task01
## File description:
## makefile
##

NAME	=	hangman

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/ all
	gcc $(SRC) -o $(NAME) -I./include -L./lib/my -lmy -g3
clean:
	make -C lib/my/ clean
	rm -f src/*.o

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re : fclean all

auteur:
	echo $(USER) > auteur
