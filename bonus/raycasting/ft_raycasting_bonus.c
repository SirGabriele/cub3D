/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 18:16:37 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_calculate_wall_height(t_math_cub *math);

void	ft_raycasting(t_game_cub *game, t_math_cub *math)
{
	int	x;

	x = 0;
	math->dir_x = cos(math->angle);
	math->dir_y = -sin(math->angle);
	ft_set_math_values(math, x);
	ft_calculate_ray_length(math);
	ft_send_ray_to_wall(game, math);
	ft_calculate_wall_height(math);
	math->wall_dist = math->perp_wall_dist;
	while (x < WIN_W)
	{
		ft_set_math_values(math, x);
		ft_calculate_ray_length(math);
		ft_send_ray_to_wall(game, math);
		ft_calculate_wall_height(math);
		if (game->map->matrix[math->map_y][math->map_x] > '0'
			&& game->map->matrix[math->map_y][math->map_x] != 'C')
			ft_draw_verline(x, game);
		if (game->map->matrix[math->map_y][math->map_x] == 'C')
			ft_draw_door_line(x, game);
		x++;
	}
}

static void	ft_calculate_wall_height(t_math_cub *math)
{
	if (math->side == 0)
		math->perp_wall_dist = (math->side_dist_x - math->delta_dist_x);
	else
		math->perp_wall_dist = (math->side_dist_y - math->delta_dist_y);
	math->line_height = (int)WIN_H / (math->perp_wall_dist);
	math->draw_start = (-math->line_height / 2) + (WIN_H / 2);
	if (math->draw_start < 0 || math->draw_start >= WIN_H)
		math->draw_start = 0;
	math->draw_end = (math->line_height / 2) + (WIN_H / 2);
	if (math->draw_end >= WIN_H || math->draw_end < 0)
		math->draw_end = WIN_H - 1;
}

void	ft_send_ray_to_wall(t_game_cub *game, t_math_cub *math)
{
	while (math->hit == 0)
	{
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (game->map->matrix[math->map_y][math->map_x] > '0'
			&& game->map->matrix[math->map_y][math->map_x] != 'O')
			math->hit = 1;
	}
}

void	ft_calculate_ray_length(t_math_cub *math)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = (math->p_x - math->map_x) * math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = (math->map_x + 1.0 - math->p_x)
			* math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = (math->p_y - math->map_y) * math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = (math->map_y + 1.0 - math->p_y)
			* math->delta_dist_y;
	}
}

void	ft_set_math_values(t_math_cub *math, int x)
{
	math->map_x = (int)math->p_x;
	math->map_y = (int)math->p_y;
	math->hit = 0;
	math->camera_x = 2 * x / (double)WIN_W - 1;
	math->ray_dir_x = math->dir_x + math->plane_x * math->camera_x;
	math->ray_dir_y = math->dir_y + math->plane_y * math->camera_x;
	math->delta_dist_x = fabs(1 / math->ray_dir_x);
	math->delta_dist_y = fabs(1 / math->ray_dir_y);
}
