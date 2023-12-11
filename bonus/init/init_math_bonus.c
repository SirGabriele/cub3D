/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:16:52 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_math_west(t_math_cub *math)
{
	math->angle = M_PI;
	math->dir_x = -1.0;
	math->dir_y = 0.0;
	math->plane_x = 0.00;
	math->plane_y = -0.99;
}

static void	init_math_east(t_math_cub *math)
{
	math->angle = 0;
	math->dir_x = 1.0;
	math->dir_y = 0.0;
	math->plane_x = 0.00;
	math->plane_y = 0.99;
}

static void	init_math_south(t_math_cub *math)
{
	math->angle = -M_PI / 2;
	math->dir_x = 0.0;
	math->dir_y = 1.0;
	math->plane_x = -0.99;
	math->plane_y = 0.00;
}

static void	init_math_north(t_math_cub *math)
{
	math->angle = M_PI / 2;
	math->dir_x = 0.0;
	math->dir_y = -1.0;
	math->plane_x = 0.99;
	math->plane_y = 0.00;
}

void	ft_init_math_value(t_game_cub *game, t_math_cub *math)
{
	if (game->spawn_dir == 'N')
		init_math_north(math);
	if (game->spawn_dir == 'S')
		init_math_south(math);
	if (game->spawn_dir == 'E')
		init_math_east(math);
	if (game->spawn_dir == 'W')
		init_math_west(math);
	math->hit = 0;
}
