/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wall_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:32:55 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:10:24 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_print_north_wall(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_y < game->math->map_y && y < WIN_H && x < WIN_W && x >= 0)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_walls[NO],
				fabs((wall_hit * game->textures->text_walls[NO]->width)
					- game->textures->text_walls[NO]->width),
				(y - game->math->draw_start)
				* game->textures->text_walls[NO]->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
	else
		ft_print_south_wall(game, wall_hit, x, y);
}

void	ft_print_south_wall(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_y > game->math->map_y && y < WIN_H && x < WIN_W && x >= 0)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_walls[SO],
				wall_hit * game->textures->text_walls[SO]->width,
				(y - game->math->draw_start)
				* game->textures->text_walls[SO]->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
}

void	ft_print_west_wall(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_x < game->math->map_x && y < WIN_H && x < WIN_W && x >= 0)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_walls[WE],
				wall_hit * game->textures->text_walls[WE]->width,
				(y - game->math->draw_start)
				* game->textures->text_walls[WE]->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
	else
		ft_print_east_wall(game, wall_hit, x, y);
}

void	ft_print_east_wall(t_game_cub *game, double wall_hit, int x, int y)
{
	int	color;

	if (game->math->p_x > game->math->map_x && y < WIN_H && x < WIN_W && x >= 0)
	{
		if ((-game->math->line_height / 2 + (WIN_H / 2)) < 0)
		{
			game->math->draw_start = (-game->math->line_height / 2)
				+ (WIN_H / 2);
			game->math->draw_end = (game->math->line_height / 2) + (WIN_H / 2);
		}
		color = get_pixel(game->textures->text_walls[EA],
				game->textures->text_walls[EA]->width
				- (wall_hit * game->textures->text_walls[EA]->width),
				(y - game->math->draw_start)
				* game->textures->text_walls[EA]->height
				/ game->math->line_height);
		color = ft_darken(game, color);
		my_mlx_pixel_put(game->mlx->screen, x, y, color);
	}
}
