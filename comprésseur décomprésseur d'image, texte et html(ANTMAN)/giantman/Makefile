##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile of project
##

SRC_MY	=	../my_src/src/my_put_char.c \
		../my_src/src/my_put_str.c \
		../my_src/src/my_put_nbr.c \
		../my_src/src/my_put_array.c \
		../my_src/src/my_put_float.c \
		../my_src/src/my_put_nbr_base.c \
		../my_src/src/my_str_to_array.c \
		../my_src/src/my_free_array.c \
		../my_src/src/my_strcpy.c \
		../my_src/src/my_strcmp.c \
		../my_src/src/my_strlen.c \
		../my_src/src/my_strcat.c \
		../my_src/src/my_str_to_int.c \
		../my_src/src/my_file_to_str.c \
		../my_src/src/my_nbr_power.c \
		../my_src/src/my_nbr_min.c \
		../my_src/src/my_nbr_max.c \
		../my_src/src/my_revstr.c \
		../my_src/src/my_is_same_letter.c \
		../my_src/src/my_char_in_str.c \
		../my_src/src/my_arraylen.c \

SRC	=	src/main.c \
		src/image_algo.c \
		src/text_algo.c \

OBJ_MY		=		$(SRC_MY:.c=.o)

OBJ     =       $(SRC:.c=.o)

NAME	=	giantman

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MY)
	gcc $(OBJ) $(OBJ_MY) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_MY)

fclean: clean
	rm -f $(NAME)

re: fclean all
