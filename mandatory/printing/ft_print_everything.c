/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_everything.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:07 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:31:23 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_print_everything(t_game_cub *game)
{
	ft_put_background(game);
	ft_raycasting(game, game->math);
	ft_put_game_cursor(game, 0, game->math->angle + (-M_PI * ROTSPEED) / 180);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->mlx->screen->img, 0, 0);
	return (0);
}
