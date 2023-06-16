##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## commande make
##

SRC 	=	src/opperation1.c   					\
			src/opperation2.c 						\
			src/opperation3.c 						\
			src/push_swap.c		    				\
			src/utils.c 							\
			src/utils2.c 							\
			src/algo.c 								\
			my_lib/flags1a5_printf.c				\
			my_lib/flags5a10_printf.c				\
			my_lib/flags10a15_printf.c				\
			my_lib/hexa.c							\
			my_lib/hexa_maj.c						\
			my_lib/my_putchar.c					\
			my_lib/my_put_nbr.c					\
			my_lib/my_putnbr_base.c				\
			my_lib/my_putnbr_u.c					\
			my_lib/my_putstr.c						\
			my_lib/my_putstr_maj.c					\
			my_lib/my_strcpy.c						\
			my_lib/octal.c							\
			my_lib/my_putnbr_base_pointeur.c		\
			my_lib/my_put_pointeur.c				\
			my_lib/binary.c						\
			my_lib/my_put_float.c					\
			my_lib/my_put_long.c					\
			my_lib/my_compute_power_it.c			\
			my_lib/my_strlen_int.c					\

OBJ     =       $(SRC:.c=.o)

NAME	=	push_swap

all	:	$(NAME)

$(NAME): 	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	 rm -f $(NAME)

re: fclean all
