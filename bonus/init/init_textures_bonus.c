/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:55:24 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	free_before_returning_null(t_textures_cub *textures, t_mlx_cub *mlx)
{
	if (textures->text_closed_door != NULL)
		free_frame(textures->text_closed_door, mlx);
	if (textures->text_diving_mask != NULL)
		free_frame(textures->text_diving_mask, mlx);
	free(textures);
}

t_textures_cub	*init_textures(t_mlx_cub *mlx)
{
	t_textures_cub	*textures;

	textures = malloc(sizeof(t_textures_cub));
	if (textures == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	textures->text_walls = NULL;
	textures->text_floor = NULL;
	textures->text_ceiling = NULL;
	textures->text_closed_door = init_frame(CLOSED_DOOR_PATH, mlx);
	textures->text_diving_mask = init_frame(DIVING_MASK_PATH, mlx);
	if (textures->text_closed_door == NULL
		|| textures->text_diving_mask == NULL)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"Could not convert file `%s`"
			" into a mlx_img\n",
			CLOSED_DOOR_PATH);
		free_before_returning_null(textures, mlx);
		return (NULL);
	}
	textures->text_bubbles = NULL;
	return (textures);
}
