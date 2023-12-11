/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:36:31 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 19:32:45 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define WIN_W 1920
# define WIN_H 1080

# define MINMAP_W 320 /*WIN_W / 6*/
# define MINMAP_H 320 /*WIN_W / 6*/

# define MINMAP_R 160 /*MINMAP_W / 2*/

# define MINMAP_PLAYER_R 4 /*WIN_W / 480*/

# define MINMAP_WALL_COLOUR 0x808080 /*gray*/
# define MINMAP_GROUND_COLOUR 0xc0c0c0 /*silver*/
# define MINMAP_LEN_RAY 15

# define PLUS_KEYPAD 65451
# define MINUS_KEYPAD 65453

# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xff0000
# define GREY 0x606060
# define BROWN 0x994C00
# define ORANGE 0xFFa500
# define PURPLE 0x800080

# define PLANE 0.99
# define ROTSPEED 1
# define MOVESPEED 10

# define BRED "\e[1;31m"
# define RESET "\e[0m"
# define NB_TEXTURES 6
# define NB_ANIMATION_FRAMES 58
# define ALLOWED_MAP_CHARSET "\n10NSEWC "
# define FILE_EXT ".cub"
# define CLOSED_DOOR_PATH "./textures/Door_water.xpm"
# define DIVING_MASK_PATH "./textures/diving_mask.xpm"

# include "libft.h"
# include "cub3D_structs_bonus.h"
# include <math.h>

# include "mlx.h"
# include "mlx_int.h"

int				launch_program(t_game_cub *game);
int				ft_close(t_game_cub *game);
void			free_game(t_game_cub *game);
void			free_mlx(t_mlx_cub *mlx);
void			free_frame(t_img_cub *frame, t_mlx_cub *mlx);

/************/
/*	Parsing	*/
/************/

int				check_element_part(t_game_cub *game);
int				check_elements_validity(const char **textures);
int				check_file_validity(const char *file_path);
int				check_map_part(t_game_cub *game);
int				initialize_bubbles(t_textures_cub *textures, t_mlx_cub *mx);
int				initialize_textures(t_textures_cub *textures,
					char **temp_textures);

/************/
/*	INIT	*/
/************/

t_img_cub		*init_bubble(int i, t_mlx_cub *mlx);
t_img_cub		*init_frame(char *path, t_mlx_cub *mlx);
t_game_cub		*init_game(const char *file_path);
t_keys_cub		init_keys(void);
t_map_cub		*init_map(void);
char			**init_matrix(int size_y, int size_x);
t_img_cub		*init_minimap(t_mlx_cub *mlx);
t_mlx_cub		*init_mlx(void);
t_img_cub		*init_screen(t_mlx_cub *mlx);
t_textures_cub	*init_textures(t_mlx_cub *mlx);
void			ft_init_math_value(t_game_cub *game, t_math_cub *math);

/********************/
/*	PARSING_UTILS	*/
/********************/

int				are_boundaries_closed(const char **matrix, int size_y,
					int size_x);
int				close_file(int file_fd, const char *file_path);
int				fill_matrix_holes(char **matrix, int size_x);
void			free_temp_textures_arr(char **textures);
int				get_index_element(const char **splitted, t_keys_cub keys,
					const char *file_line);
char			*get_first_map_line(int file_fd);
char			*get_first_non_empty_line(int file_fd);
int				get_map_infos(const char *file_path, t_map_cub *map);
int				get_player_pos(t_game_cub *game, const char **matrix);
int				is_file_finished(int file_fd);
int				is_line_empty(const char *str);
int				is_line_valid(const char **splitted, t_keys_cub keys,
					const char **textures, const char *file_line);
int				is_rgb_valid(const char *texture);
int				is_there_forbidden_char(const char *str,
					const char *allowed_charset);
int				open_o_rdonly(const char *file_path);
void			read_file_to_the_end(int file_fd, char *file_line);

/****************/
/*	RAYCASTING	*/
/****************/

void			ft_calculate_ray_length(t_math_cub *math);
void			ft_send_ray_to_wall(t_game_cub *game, t_math_cub *math);
void			ft_set_math_values(t_math_cub *math, int x);
void			ft_raycasting(t_game_cub *game, t_math_cub *math);
int				ft_send_ray_to_door(t_game_cub *game, int hit, int i);

/****************/
/*	PRINTING	*/
/****************/

int				ft_print_everything(t_game_cub *game);
void			ft_draw_verline(int x, t_game_cub *game);
void			ft_put_game_cursor(t_game_cub *game, int x, float angle);
void			ft_print_background(t_game_cub *game);
void			ft_print_celling_background(t_game_cub *game);
void			ft_print_floor_background(t_game_cub *game);
int				ft_darken(t_game_cub *game, int color);
void			draw_diving_mask(t_img_cub *text_diving_mask,
					t_img_cub *screen);
void			draw_bubbles(t_img_cub **text_bubbles, t_img_cub *screen);
void			ft_put_background(t_game_cub *game);
void			draw_minimap(t_game_cub *game);
void			ft_print_north_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_south_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_west_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_east_wall(t_game_cub *game, double wall_hit, int x,
					int y);

/************/
/*	DOOR	*/
/************/

int				ft_door(int click, int x, int y, t_game_cub *game);
void			ft_draw_door_line(int x, t_game_cub *game);
void			ft_search_door(t_game_cub *game);
void			ft_print_north_door(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_south_door(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_east_door(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_west_door(t_game_cub *game, double wall_hit, int x,
					int y);

/****************/
/*	MOVEMENT	*/
/****************/

int				use_key(int key, t_game_cub *game);
int				ft_check_move_up_x(t_game_cub *game, t_math_cub *math);
int				ft_check_move_up_y(t_game_cub *game, t_math_cub *math);
int				ft_check_move_down_x(t_game_cub *game, t_math_cub *math);
int				ft_check_move_down_y(t_game_cub *game, t_math_cub *math);
int				ft_check_move_left_x(t_game_cub *game, t_math_cub *math);
int				ft_check_move_left_y(t_game_cub *game, t_math_cub *math);
int				ft_check_move_right_x(t_game_cub *game, t_math_cub *math);
int				ft_check_move_right_y(t_game_cub *game, t_math_cub *math);
int				ft_move_cursor(int x, int y, t_game_cub *game);

/********************/
/*	PRINTING_UTILS	*/
/********************/

int				convert_rgb_into_int(int rgb[3]);
int				get_matrix_coord_colour(t_game_cub *game, int pixel_x,
					int pixel_y);
int				get_pixel(t_img_cub *frame, int x, int y);
void			my_mlx_pixel_put(t_img_cub *img, int x, int y, int colour);

#endif
