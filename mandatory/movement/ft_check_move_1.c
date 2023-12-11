/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_move_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:06:07 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_move_up_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	x = (float)(math->p_x + (cos(math->angle) / MOVESPEED * 3))
		+ cos(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	x = math->p_x + cos(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	return (0);
}

int	ft_check_move_up_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	y = (float)(math->p_y - (sin(math->angle) / MOVESPEED * 3))
		- sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	y = math->p_y - sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	return (0);
}

int	ft_check_move_down_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	x = (float)(math->p_x - (cos(math->angle) / MOVESPEED * 3))
		- cos(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	x = math->p_x - cos(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	return (0);
}

int	ft_check_move_down_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	y = (float)(math->p_y + (sin(math->angle) / MOVESPEED * 3))
		+ sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	y = math->p_y + sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	return (0);
}

int	ft_check_move_left_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	x = (float)(math->p_x - (sin(math->angle) / MOVESPEED * 3))
		- sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	x = math->p_x - sin(math->angle) / MOVESPEED;
	if (game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'O')
		return (1);
	return (0);
}
