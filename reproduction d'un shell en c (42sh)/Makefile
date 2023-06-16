##
## EPITECH PROJECT, 2023
## makefile
## File description:
## make compile, clean, fclean, re...
##

SRC			=	$(wildcard src/*.c)

NAME		=	42sh

DEBUG_NAME	=	$(NAME)-debug

LIB			=	./lib/my/

LIBNAME		=	libmy.a

HEADERS		=	./includes/

FLAGS		=	-L$(LIB) -lmy -I$(HEADERS)

DEBUG_FLAGS	=	-Wall -Wextra -g3

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	$(FLAGS)

all:	$(NAME)

$(NAME):	compile

compile:	$(LIBNAME) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS)
	@echo "\033[32mCompilation success\033[0m"

debug:		$(LIBNAME)
	gcc $(SRC) -o $(DEBUG_NAME) $(FLAGS) $(DEBUG_FLAGS)
	@echo "\33[34mDebug compilation sucess\033[0m"

$(LIBNAME):
	make -C lib/my/
	cp $(LIB)$(LIBNAME) ./lib/

clean:
	make -C $(LIB) clean
	@find . -name *~ -delete
	@find . -name *.swp -delete
	@rm -f $(OBJ)
	@find . -name vgcore* -delete
	@echo "\033[33mSuccessfully removed useless files\33[0m"

fclean:	clean
	make -C $(LIB) fclean
	@rm -rf $(NAME)
	@rm -rf $(DEBUG_NAME)
	@echo "\033[31mSuccessfully purged the repo\033[0m"

check_functions: $(LIBNAME) compile
	@epitech_function_checker $(NAME)

cs:	check_functions debug fclean
	@abricot .
	@echo "\033[32m--- report made ---\033[0m"

re:	fclean	compile

re-debug:	fclean debug

push: cs
	@git pull
	@git add .
	@echo -n "Commit message > "
	@read message; git commit -m "$$message"
	@git push
