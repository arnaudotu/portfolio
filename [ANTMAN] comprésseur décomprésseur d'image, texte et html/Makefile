##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile of project
##

SRC_MY	=	my_src/src/my_put_char.c \
		my_src/src/my_put_str.c \
		my_src/src/my_put_nbr.c \
		my_src/src/my_put_array.c \
		my_src/src/my_put_float.c \
		my_src/src/my_put_nbr_base.c \
		my_src/src/my_str_to_array.c \
		my_src/src/my_free_array.c \
		my_src/src/my_strcpy.c \
		my_src/src/my_strcmp.c \
		my_src/src/my_strlen.c \
		my_src/src/my_strcat.c \
		my_src/src/my_str_to_int.c \
		my_src/src/my_file_to_str.c \
		my_src/src/my_nbr_power.c \
		my_src/src/my_nbr_min.c \
		my_src/src/my_nbr_max.c \
		my_src/src/my_revstr.c \
		my_src/src/my_is_same_letter.c \
		my_src/src/my_char_in_str.c \
		my_src/src/my_arraylen.c \

SRC_ANT = antman/src/main.c \
			antman/src/text_algo.c \
			antman/src/image_algo.c \

SRC_GIA = giantman/src/main.c \
			giantman/src/image_algo.c \
			giantman/src/text_algo.c \

OBJ_ANT     =       $(SRC_ANT:.c=.o)

OBJ_GIA     =       $(SRC_GIA:.c=.o)

OBJ_MY		=		$(SRC_MY:.c=.o)

NAME_ANT	=	antman

NAME_GIA	=	giantman

all:	$(NAME_ANT)

$(NAME_ANT):	$(OBJ_MY) $(OBJ_ANT) $(OBJ_GIA)
	gcc $(OBJ_ANT) $(OBJ_MY) -o antman/$(NAME_ANT)
	gcc $(OBJ_GIA) $(OBJ_MY) -o giantman/$(NAME_GIA)

clean:
	rm -f $(OBJ_MY)
	rm -f $(OBJ_ANT)
	rm -f $(OBJ_GIA)

fclean: clean
	rm -f ./antman/$(NAME_ANT)
	rm -f ./giantman/$(NAME_GIA)

re: fclean all
