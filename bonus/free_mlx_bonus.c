/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:40 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:01:29 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_mlx(t_mlx_cub *mlx)
{
	if (mlx->screen != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->screen->img);
		free(mlx->screen);
		mlx->screen = NULL;
	}
	if (mlx->background != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->background->img);
		free(mlx->background);
		mlx->background = NULL;
	}
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr != NULL)
	{
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	free(mlx);
	mlx = NULL;
}
