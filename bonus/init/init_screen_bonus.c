/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:55:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_img_cub	*init_screen(t_mlx_cub *mlx)
{
	t_img_cub	*screen;

	screen = malloc(sizeof(t_img_cub));
	if (screen == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	screen->img = mlx_new_image(mlx->mlx_ptr, WIN_W,
			WIN_H);
	if (screen->img == NULL)
	{
		free(screen);
		return (NULL);
	}
	screen->addr = mlx_get_data_addr(screen->img,
			&(screen->bpp), &(screen->line_length), &(screen->endian));
	return (screen);
}
