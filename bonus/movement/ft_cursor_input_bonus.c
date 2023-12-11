/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:37:33 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 14:27:54 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_move_cursor(int x, int y, t_game_cub *game)
{
	(void)y;
	if (x > game->mouse_x)
	{
		game->math->angle = game->math->angle + (-M_PI * ROTSPEED) / 180;
		game->math->plane_x = sin(game->math->angle) * PLANE;
		game->math->plane_y = cos(game->math->angle) * PLANE;
		mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->win_ptr, WIN_H / 2,
			WIN_W / 2);
		mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr,
			&game->mouse_x, &game->mouse_y);
	}
	else if (x < game->mouse_x)
	{
		game->math->angle = game->math->angle + (M_PI * ROTSPEED) / 180;
		game->math->plane_x = sin(game->math->angle) * PLANE;
		game->math->plane_y = cos(game->math->angle) * PLANE;
		mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->win_ptr, WIN_H / 2,
			WIN_W / 2);
		mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr,
			&game->mouse_x, &game->mouse_y);
	}
	return (0);
}

int	ft_print_everything(t_game_cub *game)
{
	ft_put_background(game);
	ft_raycasting(game, game->math);
	draw_bubbles(game->textures->text_bubbles, game->mlx->screen);
	draw_diving_mask(game->textures->text_diving_mask, game->mlx->screen);
	draw_minimap(game);
	ft_put_game_cursor(game, 0, game->math->angle + (-M_PI * ROTSPEED) / 180);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->mlx->screen->img, 0, 0);
	return (0);
}
