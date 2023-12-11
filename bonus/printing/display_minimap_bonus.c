/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:41:42 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	draw_minimap_player(t_img_cub *screen)
{
	int	center_x;
	int	center_y;
	int	x;
	int	y;

	center_x = MINMAP_W / 2;
	center_y = MINMAP_H / 2;
	y = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	while (y < (MINMAP_H / 2) + MINMAP_PLAYER_R)
	{
		x = (MINMAP_H / 2) - MINMAP_PLAYER_R;
		while (x < (MINMAP_H / 2) + MINMAP_PLAYER_R)
		{
			if (round(sqrt(pow(x - center_x, 2) + pow(y - center_y, 2)))
				< MINMAP_PLAYER_R)
				my_mlx_pixel_put(screen, 20 + x, 20 + y, RED);
			x++;
		}
		y++;
	}
}

static int	ft_check_ray_path(t_game_cub *game, t_img_cub *screen, int x, int y)
{
	int	color;

	color = get_pixel(screen, 20 + x, 20 + y);
	if (color != convert_rgb_into_int(game->textures->text_floor_int)
		&& color != WHITE
		&& color != PURPLE)
		return (1);
	return (0);
}

static void	draw_minimap_player_ray(t_img_cub *screen, t_game_cub *game)
{
	double	dx;
	double	dy;
	double	center_x;
	double	center_y;
	int		px_length;

	center_x = MINMAP_W / 2;
	center_y = MINMAP_H / 2;
	dx = ((center_x + MINMAP_R * game->math->dir_x) - center_x);
	dy = ((center_y + MINMAP_R * game->math->dir_y) - center_y);
	px_length = sqrt((dx * dx) + (dy * dy));
	dx /= px_length;
	dy /= px_length;
	while (px_length
		&& ft_check_ray_path(game, screen, center_x, center_y) == 0)
	{
		my_mlx_pixel_put(screen, 20 + center_x, 20 + center_y, WHITE);
		center_x += dx;
		center_y += dy;
		px_length--;
	}
}

static void	draw_minimap_circle(t_img_cub *screen, t_game_cub *game)
{
	int	y;
	int	x;
	int	center_x;
	int	center_y;
	int	value;

	center_x = MINMAP_W / 2;
	center_y = MINMAP_H / 2;
	y = 0;
	while (y < MINMAP_H)
	{
		x = 0;
		while (x < MINMAP_W)
		{
			value = round(sqrt(pow(x - center_x, 2) + pow(y - center_y, 2)));
			if (value == MINMAP_R - 3 || value == MINMAP_R - 2
				|| value == MINMAP_R - 1)
				my_mlx_pixel_put(screen, 20 + x, 20 + y, WHITE);
			else if (value < MINMAP_R - 1)
				my_mlx_pixel_put(screen, 20 + x, 20 + y,
					get_matrix_coord_colour(game, x, y));
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game_cub *game)
{
	draw_minimap_circle(game->mlx->screen, game);
	draw_minimap_player_ray(game->mlx->screen, game);
	draw_minimap_player(game->mlx->screen);
}
