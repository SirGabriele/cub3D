/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_program_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:13:52 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:55:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_close(t_game_cub *game);

int	launch_program(t_game_cub *game)
{
	game->mlx->screen = init_screen(game->mlx);
	if (game->mlx->screen == NULL)
		return (1);
	ft_print_background(game);
	mlx_hook(game->mlx->win_ptr, 2, 1L << 0, use_key, game);
	mlx_hook(game->mlx->win_ptr, 17, 1L << 2, ft_close, game);
	mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr,
		&game->mouse_x, &game->mouse_y);
	mlx_mouse_hook(game->mlx->win_ptr, ft_door, game);
	mlx_hook(game->mlx->win_ptr, MotionNotify, PointerMotionMask,
		ft_move_cursor, game);
	mlx_loop_hook(game->mlx->mlx_ptr, ft_print_everything, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}

int	ft_close(t_game_cub *game)
{
	free_game(game);
	exit(0);
	return (0);
}
