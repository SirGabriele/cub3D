/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:59:53 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:10:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_print_north_door(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_y < game->math->map_y)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2)
				+ (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_closed_door,
				fabs((wall_hit * game->textures->text_closed_door->width)
					- game->textures->text_closed_door->width),
				(y - game->math->draw_start)
				* game->textures->text_closed_door->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
	else
		ft_print_south_door(game, wall_hit, x, y);
}

void	ft_print_south_door(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_y > game->math->map_y)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_closed_door,
				wall_hit * game->textures->text_closed_door->width,
				(y - game->math->draw_start)
				* game->textures->text_closed_door->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
}

void	ft_print_east_door(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_x < game->math->map_x)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_closed_door,
				wall_hit * game->textures->text_closed_door->width,
				(y - game->math->draw_start)
				* game->textures->text_closed_door->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
	else
		ft_print_west_door(game, wall_hit, x, y);
}

void	ft_print_west_door(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_x > game->math->map_x)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_closed_door,
				game->textures->text_closed_door->width
				- (wall_hit * game->textures->text_closed_door->width),
				(y - game->math->draw_start)
				* game->textures->text_closed_door->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
}
