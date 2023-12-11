/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structs_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:38:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 14:38:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_BONUS_H
# define CUB3D_STRUCTS_BONUS_H

typedef enum s_enum_textures_cub
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_enum_textures_cub;

typedef struct s_keys_cub
{
	char	*keys[NB_TEXTURES];
}	t_keys_cub;

typedef struct s_math_cub
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	line_height;
	int		draw_start;
	int		draw_end;
	int		movespeed;
	int		rot_speed;
	float	plane;
	float	p_x;
	float	p_y;
	float	angle;
	double	time;
	double	oldtime;
	double	side_dist_x;
	double	side_dist_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_dist;
}	t_math_cub;

typedef struct s_img_cub
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img_cub;

typedef struct s_textures_cub
{
	t_img_cub	**text_walls;
	t_img_cub	*text_closed_door;
	t_img_cub	*text_diving_mask;
	t_img_cub	**text_bubbles;
	char		**text_floor;
	char		**text_ceiling;
	int			text_floor_int[3];
	int			text_ceiling_int[3];
}	t_textures_cub;

typedef struct s_mlx_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_cub	*screen;
	t_img_cub	*background;
}	t_mlx_cub;

typedef struct s_map_cub
{
	char	**matrix;
	int		size_y;
	int		size_x;
}	t_map_cub;

typedef struct s_game_cub
{
	t_map_cub		*map;
	t_mlx_cub		*mlx;
	t_textures_cub	*textures;
	const char		*file_path;
	float			minimap_ratio_y;
	float			minimap_ratio_x;
	int				mouse_x;
	int				mouse_y;
	unsigned int	minimap_zoom;
	char			spawn_dir;
	t_math_cub		*math;
}	t_game_cub;

#endif
