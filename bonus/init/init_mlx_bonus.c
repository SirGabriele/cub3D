/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:59:24 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:14:15 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_mlx_cub	*init_mlx(void)
{
	t_mlx_cub	*mlx;

	mlx = malloc(sizeof(t_mlx_cub));
	if (mlx == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H,
			"Cub3D of the Raie-Castor !");
	if (mlx->mlx_ptr == NULL || mlx->win_ptr == NULL)
		return (NULL);
	mlx->screen = NULL;
	mlx->background = NULL;
	return (mlx);
}
