NAME				=	cub3D 

SRC					=	main.c				\
						launch_program.c	\
						free_game.c			\
						free_mlx.c

SRC_B				=	main_bonus.c			\
						launch_program_bonus.c	\
						free_game_bonus.c		\
						free_mlx_bonus.c

PARSING				=	check_element_part.c		\
						check_elements_validity.c	\
						check_file_validity.c		\
						check_map_part.c			\
						initialize_textures.c

PARSING_B			=	check_element_part_bonus.c		\
						check_elements_validity_bonus.c	\
						check_file_validity_bonus.c		\
						check_map_part_bonus.c			\
						initialize_bubbles_bonus.c		\
						initialize_textures_bonus.c

PARSING_UTILS		=	are_boundaries_closed.c		\
						fill_matrix_holes.c			\
						free_temp_textures_arr.c	\
						get_index_element.c			\
						get_first_map_line.c		\
						get_first_non_empty_line.c	\
						get_map_infos.c				\
						is_file_finished.c			\
						is_line_empty.c				\
						is_line_valid.c				\
						is_rgb_valid.c				\
						is_there_forbidden_char.c	\
						open_close.c				\
						player_pos.c				\
						read_file_to_the_end.c

PARSING_UTILS_B		=	are_boundaries_closed_bonus.c		\
						fill_matrix_holes_bonus.c			\
						free_temp_textures_arr_bonus.c		\
						get_index_element_bonus.c			\
						get_first_map_line_bonus.c			\
						get_first_non_empty_line_bonus.c	\
						get_map_infos_bonus.c				\
						is_file_finished_bonus.c			\
						is_line_empty_bonus.c				\
						is_line_valid_bonus.c				\
						is_rgb_valid_bonus.c				\
						is_there_forbidden_char_bonus.c		\
						open_close_bonus.c					\
						player_pos_bonus.c					\
						read_file_to_the_end_bonus.c

RAYCASTING			=	ft_raycasting.c		\
						ft_draw_verline.c

RAYCASTING_B		=	ft_raycasting_bonus.c	\
						ft_draw_verline_bonus.c

MOVEMENT			=	key_input.c			\
						ft_check_move_1.c	\
						ft_check_move_2.c

MOVEMENT_B			=	ft_cursor_input_bonus.c	\
						key_input_bonus.c		\
						ft_check_move_1_bonus.c	\
						ft_check_move_2_bonus.c	\
						ft_door_ex_bonus.c

PRINTING			=	ft_print_background.c	\
						ft_print_everything.c	\
						ft_print_wall.c

PRINTING_B			=	ft_print_background_bonus.c		\
						draw_diving_mask_bonus.c		\
						draw_bubbles_bonus.c			\
						display_minimap_bonus.c			\
						ft_print_wall_bonus.c			\
						ft_print_door_bonus.c

PRINTING_UTILS		=	convert_rgb_into_int.c		\
						get_pixel.c					\
						my_mlx_pixel_put.c

PRINTING_UTILS_B	=	convert_rgb_into_int_bonus.c		\
						get_matrix_coord_colour_bonus.c		\
						get_pixel_bonus.c					\
						my_mlx_pixel_put_bonus.c

INIT				=	init_frame.c			\
						init_game.c			\
						init_keys.c			\
						init_map.c			\
						init_matrix.c			\
						init_mlx.c			\
						init_screen.c			\
						init_textures.c		\
						init_math.c

INIT_B				=	init_bubble_bonus.c			\
						init_frame_bonus.c			\
						init_game_bonus.c			\
						init_keys_bonus.c			\
						init_map_bonus.c			\
						init_matrix_bonus.c			\
						init_minimap_bonus.c		\
						init_mlx_bonus.c			\
						init_screen_bonus.c			\
						init_textures_bonus.c		\
						init_math_bonus.c

INCLUDE_FOLDER 		=	-I mandatory/include	\
						-I minilibx-linux		\
						-I libft

INCLUDE_FOLDER_B	=	-I bonus/include	\
						-I minilibx-linux	\
						-I libft

LIBRARIES			=	-Lminilibx-linux -lmlx -lXext -lX11 -lm	\
						-Llibft -lft

HEADER_FILES		=	libft/libft.h						\
						minilibx-linux/mlx.h				\
						minilibx-linux/mlx_int.h			\
						mandatory/include/cub3D.h			\
						mandatory/include/cub3D_structs.h

HEADER_FILES_B		=	libft/libft.h						\
						minilibx-linux/mlx.h				\
						minilibx-linux/mlx_int.h			\
						bonus/include/cub3D_bonus.h			\
						bonus/include/cub3D_structs_bonus.h

SRCS				=	$(addprefix mandatory/, $(SRC))							\
						$(addprefix mandatory/parsing/, $(PARSING))				\
						$(addprefix mandatory/parsing_utils/, $(PARSING_UTILS))	\
						$(addprefix mandatory/init/, $(INIT))					\
						$(addprefix mandatory/movement/, $(MOVEMENT))				\
						$(addprefix mandatory/raycasting/, $(RAYCASTING))			\
						$(addprefix mandatory/printing/, $(PRINTING))				\
						$(addprefix mandatory/printing_utils/, $(PRINTING_UTILS))
						


SRCS_B				=	$(addprefix bonus/, $(SRC_B))							\
						$(addprefix bonus/parsing/, $(PARSING_B))				\
						$(addprefix bonus/parsing_utils/, $(PARSING_UTILS_B))	\
						$(addprefix bonus/init/, $(INIT_B))						\
						$(addprefix bonus/minimap/, $(MINIMAP_B))				\
						$(addprefix bonus/movement/, $(MOVEMENT_B))				\
						$(addprefix bonus/raycasting/, $(RAYCASTING_B))			\
						$(addprefix bonus/printing/, $(PRINTING_B))				\
						$(addprefix bonus/printing_utils/, $(PRINTING_UTILS_B))



CC					=	clang

FLAGS				=	-Wall -Wextra -Werror -g3

OBJS				=	$(SRCS:.c=.o)

OBJS_B				=	$(SRCS_B:.c=.o)

ifdef BONUS
	SRCS			=	$(SRCS_B)
	INCLUDE_FOLDER	=	$(INCLUDE_FOLDER_B)
	HEADER_FILES	=	$(HEADER_FILES_B)
endif

all: $(NAME)

clean:
	rm -f $(OBJS_B) $(OBJS)
	make clean -C libft
	make clean -C minilibx-linux

fclean:	clean
	make fclean -C libft
	rm -f $(NAME)

re:	fclean all

%.o: %.c $(HEADER_FILES)
	$(CC) $(FLAGS) $(INCLUDE_FOLDER) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)

bonus:
	make BONUS=1

.PHONY: all clean fclean re bonus
