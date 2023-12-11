/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:36:31 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:04:43 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_W 1920
# define WIN_H 1080

# define PLANE 0.99
# define ROTSPEED 1
# define MOVESPEED 10

# define BLACK 0x000000

# define BRED "\e[1;31m"
# define RESET "\e[0m"
# define NB_TEXTURES 6
# define ALLOWED_MAP_CHARSET "\n10NSEW "
# define FILE_EXT ".cub"

# include "libft.h"
# include "cub3D_structs.h"
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
int				initialize_textures(t_textures_cub *textures,
					char **temp_textures);

/************/
/*	INIT	*/
/************/

t_img_cub		*init_frame(char *path, t_mlx_cub *mlx);
t_game_cub		*init_game(const char *file_path);
t_keys_cub		init_keys(void);
t_map_cub		*init_map(void);
char			**init_matrix(int size_y, int size_x);
t_mlx_cub		*init_mlx(void);
t_img_cub		*init_screen(t_mlx_cub *mlx);
t_textures_cub	*init_textures(void);
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

/****************/
/*	PRINTING	*/
/****************/

int				ft_print_everything(t_game_cub *game);
void			ft_draw_verline(int x, t_game_cub *game);
void			ft_put_game_cursor(t_game_cub *game, int x, float angle);
void			ft_print_background(t_game_cub *game);
void			ft_print_celling_background(t_game_cub *game);
void			ft_print_floor_background(t_game_cub *game);
void			ft_put_background(t_game_cub *game);
void			ft_print_north_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_south_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_west_wall(t_game_cub *game, double wall_hit, int x,
					int y);
void			ft_print_east_wall(t_game_cub *game, double wall_hit, int x,
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

/********************/
/*	PRINTING_UTILS	*/
/********************/

int				convert_rgb_into_int(int rgb[3]);
int				get_pixel(t_img_cub *frame, int x, int y);
void			my_mlx_pixel_put(t_img_cub *img, int x, int y, int colour);

#endif
