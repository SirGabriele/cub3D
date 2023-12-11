/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:59:39 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:59:39 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_img_cub	*init_minimap(t_mlx_cub *mlx)
{
	t_img_cub	*minimap;

	minimap = malloc(sizeof(t_img_cub));
	if (minimap == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	minimap->img = mlx_new_image(mlx->mlx_ptr, MINMAP_W,
			MINMAP_H);
	if (minimap->img == NULL)
	{
		free(minimap);
		return (NULL);
	}
	minimap->addr = mlx_get_data_addr(minimap->img,
			&(minimap->bpp), &(minimap->line_length), &(minimap->endian));
	return (minimap);
}
