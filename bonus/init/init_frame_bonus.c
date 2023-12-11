/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:02 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:54:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_img_cub	*init_frame(char *path, t_mlx_cub *mlx)
{
	t_img_cub	*frame;

	frame = malloc(sizeof(t_img_cub));
	if (frame == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	frame->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&frame->width, &frame->height);
	if (frame->img == NULL)
	{
		free(frame);
		return (NULL);
	}
	frame->addr = mlx_get_data_addr(frame->img, &(frame->bpp),
			&(frame->line_length), &(frame->endian));
	return (frame);
}
