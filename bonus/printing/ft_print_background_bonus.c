/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_background_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:20:59 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:00:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_print_background(t_game_cub *game)
{
	game->mlx->background = init_screen(game->mlx);
	ft_print_celling_background(game);
	ft_print_floor_background(game);
}

void	ft_print_floor_background(t_game_cub *game)
{
	int	x;
	int	y;
	int	color;	
	int	col_f[3];

	x = WIN_H / 2;
	y = 0;
	color = convert_rgb_into_int(game->textures->text_floor_int);
	while (x <= WIN_H)
	{
		while (y < WIN_W)
		{
			if (x > (WIN_H / 2) - 100)
				my_mlx_pixel_put(game->mlx->background, y, x, color);
			else if (x > (WIN_H / 2))
				my_mlx_pixel_put(game->mlx->background, y, x, BLACK);
			y++;
		}
		y = 0;
		x++;
		col_f[0] = game->textures->text_floor_int[0] - fabs((x - WIN_H) / 2.5);
		col_f[1] = game->textures->text_floor_int[1] - fabs((x - WIN_H) / 2.5);
		col_f[2] = game->textures->text_floor_int[2] - fabs((x - WIN_H) / 2.5);
		color = convert_rgb_into_int(col_f);
	}
}

void	ft_print_celling_background(t_game_cub *game)
{
	int	x;
	int	y;
	int	color;	
	int	color_c[3];

	x = WIN_H / 2;
	y = 0;
	color = convert_rgb_into_int(game->textures->text_ceiling_int);
	while (x >= 0)
	{
		while (y < WIN_W)
		{
			if (x <= (WIN_H / 2) - 100)
				my_mlx_pixel_put(game->mlx->background, y, x, color);
			else if (x <= WIN_H / 2)
				my_mlx_pixel_put(game->mlx->background, y, x, 0);
			y++;
		}
		y = 0;
		x--;
		color_c[0] = game->textures->text_ceiling_int[0] - (x / 1.75) + 1;
		color_c[1] = game->textures->text_ceiling_int[1] - (x / 1.75) + 1;
		color_c[2] = game->textures->text_ceiling_int[2] - (x / 1.75) + 1;
		color = convert_rgb_into_int(color_c);
	}
}

void	ft_put_background(t_game_cub *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			color = get_pixel(game->mlx->background, x, y);
			my_mlx_pixel_put(game->mlx->screen, x, y, color);
			x++;
		}
		y++;
	}
}
