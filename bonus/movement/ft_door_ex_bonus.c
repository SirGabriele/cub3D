/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_ex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:09:19 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:11:15 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_search_door(t_game_cub *game)
{
	int	x;
	int	i;
	int	hit;

	hit = 0;
	i = 0;
	x = WIN_W / 2;
	game->math->dir_x = cos(game->math->angle);
	game->math->dir_y = -sin(game->math->angle);
	ft_set_math_values(game->math, x);
	ft_calculate_ray_length(game->math);
	hit = ft_send_ray_to_door(game, hit, i);
	if (hit == 1)
		game->map->matrix[game->math->map_y][game->math->map_x] = 'O';
	if (hit == 2)
		game->map->matrix[game->math->map_y][game->math->map_x] = 'C';
}

int	ft_send_ray_to_door(t_game_cub *game, int hit, int i)
{
	while (hit == 0)
	{
		if (game->math->side_dist_x < game->math->side_dist_y)
		{
			game->math->side_dist_x += game->math->delta_dist_x;
			game->math->map_x += game->math->step_x;
			game->math->side = 0;
		}
		else
		{
			game->math->side_dist_y += game->math->delta_dist_y;
			game->math->map_y += game->math->step_y;
			game->math->side = 1;
		}
		if (game->map->matrix[game->math->map_y][game->math->map_x] == 'C')
			hit = 1;
		if (game->map->matrix[game->math->map_y][game->math->map_x] == 'O')
			hit = 2;
		if (game->map->matrix[game->math->map_y][game->math->map_x] == '1')
			hit = 3;
		i++;
	}
	if (i <= 4 && i > 0)
		return (hit);
	return (0);
}

int	ft_door(int click, int x, int y, t_game_cub *game)
{
	(void)x;
	(void)y;
	if (click == 1)
		ft_search_door(game);
	return (0);
}
