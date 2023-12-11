/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:20:59 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:00:51 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

	x = WIN_H / 2;
	y = 0;
	color = convert_rgb_into_int(game->textures->text_floor_int);
	while (x <= WIN_H)
	{
		while (y < WIN_W)
		{
			if (x > WIN_H / 2)
				my_mlx_pixel_put(game->mlx->background, y, x, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_print_celling_background(t_game_cub *game)
{
	int	x;
	int	y;
	int	color;	

	x = WIN_H / 2;
	y = 0;
	color = convert_rgb_into_int(game->textures->text_ceiling_int);
	while (x >= 0)
	{
		while (y < WIN_W)
		{
			if (x <= WIN_H / 2)
				my_mlx_pixel_put(game->mlx->background, y, x, color);
			y++;
		}
		y = 0;
		x--;
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
