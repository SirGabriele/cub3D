/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_verline_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:57:09 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:31:25 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_verline(int x, t_game_cub *game)
{
	int		i;
	int		y;
	double	wall_hit;

	i = 0;
	y = game->math->draw_start;
	if (game->math->side == 0)
		wall_hit = game->math->p_y + game->math->perp_wall_dist
			* game->math->ray_dir_y;
	else
		wall_hit = game->math->p_x + game->math->perp_wall_dist
			* game->math->ray_dir_x;
	wall_hit -= floor(wall_hit);
	while (y <= game->math->draw_end)
	{
		if (game->math->side == 1)
			ft_print_north_wall(game, wall_hit, x, y);
		else
			ft_print_west_wall(game, wall_hit, x, y);
		y++;
	}
}

void	ft_draw_door_line(int x, t_game_cub *game)
{
	int		i;
	int		y;
	double	wall_hit;

	i = 0;
	y = game->math->draw_start;
	if (game->math->side == 0)
		wall_hit = game->math->p_y + game->math->perp_wall_dist
			* game->math->ray_dir_y;
	else
		wall_hit = game->math->p_x + game->math->perp_wall_dist
			* game->math->ray_dir_x;
	wall_hit -= floor(wall_hit);
	while (y <= game->math->draw_end)
	{
		if (y < WIN_H && x < WIN_W && x >= 0)
		{
			if (game->math->side == 1)
				ft_print_north_door(game, wall_hit, x, y);
			else
				ft_print_east_door(game, wall_hit, x, y);
		}
		y++;
	}
}

int	ft_darken(t_game_cub *game, int color)
{
	int	color_tab[3];
	int	r;
	int	g;
	int	b;

	if (game->math->perp_wall_dist > 25)
		return (0);
	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	if (game->math->perp_wall_dist > 5)
	{
		color_tab[0] = r / ((1.0 * (game->math->perp_wall_dist - 5) + 1));
		color_tab[1] = g / ((1.0 * (game->math->perp_wall_dist - 5) + 1));
		color_tab[2] = b / ((1.0 * (game->math->perp_wall_dist - 5) + 1));
		color = convert_rgb_into_int(color_tab);
	}
	return (color);
}

void	ft_put_game_cursor(t_game_cub *game, int x, float angle)
{
	float	angle_x;
	float	angle_y;
	float	plane_x;
	float	plane_y;

	angle_x = cos(game->math->angle) * 10;
	angle_y = -sin(game->math->angle) * 10;
	plane_x = sin(game->math->angle) * PLANE;
	plane_y = cos(game->math->angle) * PLANE;
	while (x <= 360)
	{
		my_mlx_pixel_put(game->mlx->screen, WIN_W / 2 + angle_x
			* game->math->plane_x, WIN_H / 2 + angle_y, 0xffffff);
		my_mlx_pixel_put(game->mlx->screen, WIN_W / 2 + angle_x,
			WIN_H / 2 + angle_y * game->math->plane_y, 0xffffff);
		angle = angle + (M_PI * ROTSPEED) / 180;
		angle_x = cos(angle) * 10;
		angle_y = -sin(angle) * 10;
		plane_x = sin(angle) * PLANE;
		plane_y = cos(angle) * PLANE;
		x++;
	}
}
