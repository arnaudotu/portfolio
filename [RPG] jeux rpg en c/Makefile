##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile of project
##

SRC_MY	=	src/my/my_putchar.c \
		src/my/my_putstr.c \
		src/my/my_putnbr.c \
		src/my/my_put_array.c \
		src/my/my_putfloat.c \
		src/my/my_putnbr_base.c \
		src/my/my_str_to_array.c \
		src/my/my_free_array.c \
		src/my/my_strcpy.c \
		src/my/my_strcmp.c \
		src/my/my_strlen.c \
		src/my/my_strcat.c \
		src/my/my_str_to_int.c \
		src/my/my_file_to_str.c \
		src/my/my_nbr_power.c \
		src/my/my_nbr_min.c \
		src/my/my_nbr_max.c \
		src/my/my_revstr.c \
		src/my/my_is_same_letter.c \
		src/my/my_is_number.c \
		src/my/my_is_letter.c \
		src/my/my_is_float.c \
		src/my/my_is_word.c \
		src/my/my_sort_array_alpha.c \
		src/my/my_is_str_in_str.c \
		src/my/my_is_str_in_array.c \
		src/my/my_char_in_str.c \
		src/my/my_arraylen.c \
		src/my/my_filesize.c \
		src/my/my_is_file.c \
		src/my/my_is_directory.c \
		src/my/my_int_to_binary.c \
		src/my/my_nbrlen.c \
		src/my/my_is_between.c \
		src/my/my_binary_to_nbr.c \

SRC_MY_CSFML = src/my_csfml/my_csfml_window.c \
		src/my_csfml/my_csfml_object.c \
		src/my_csfml/my_csfml_event.c \
		src/my_csfml/my_csfml_rect.c \
		src/my_csfml/my_csfml_time.c \
		src/my_csfml/my_csfml_object_movement.c \
		src/my_csfml/my_csfml_object_animation.c \
		src/my_csfml/my_csfml_object_list.c \
		src/my_csfml/my_csfml_collision.c \
		src/my_csfml/my_csfml_audio.c \
		src/my_csfml/my_csfml_camera.c \
		src/my_csfml/my_csfml_tilemap.c \
		src/my_csfml/my_csfml_tilemap_list.c \
		src/my_csfml/my_csfml_text.c \

SRC_GAME = src/main.c \
		src/RPG/player/init_player.c \
		src/RPG/player/player_movement.c \
		src/RPG/player/player_animation.c \
		src/RPG/input/check_user_move_input.c \
		src/RPG/input/check_user_action_input.c \
		src/RPG/camera/camera_movement.c \
		src/RPG/buttons/init_button.c \
		src/RPG/buttons/button_check.c \
		src/RPG/menu/init_menu.c \
		src/RPG/menu/menu_button_command.c \
		src/RPG/menu/setting_button_command.c \
		src/RPG/buttons/test_commands.c \
		src/RPG/world/init_world.c \
		src/RPG/world/world_collision.c \
		src/RPG/world/world_dialogue_init.c \
		src/RPG/dialogue/init_dialogue.c \
		src/RPG/dialogue/dialogue_manage.c \
		src/RPG/speak/init_speak.c \
		src/RPG/functions/init_function_pointer.c \
		src/RPG/functions/set_functions_forest.c \
		src/RPG/functions/set_functions_casino.c \
		src/RPG/functions/set_functions_desert.c \
		src/RPG/functions/set_functions_tower.c \
		src/RPG/timing/wait_functions.c \
		src/RPG/timing/transition_functions.c \
		src/RPG/teleport/init_teleport.c \
		src/RPG/music/music.c \
		src/RPG/battle/init_battle.c \
		src/RPG/battle/player_battle.c \
		src/RPG/battle/battle_button_actions.c \
		src/RPG/instances/instances.c \
		src/RPG/ennemy/init_ennemy.c \

OBJ     =       $(SRC_MY:.c=.o) \
			$(SRC_MY_CSFML:.c=.o) \
			$(SRC_GAME:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -lcsfml-audio -lcsfml-graphics \
	-lcsfml-system -lcsfml-window -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
