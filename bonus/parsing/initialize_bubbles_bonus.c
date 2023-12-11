/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bubbles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:56:31 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:56:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	initialize_bubbles(t_textures_cub *textures, t_mlx_cub *mlx)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	textures->text_bubbles = malloc(sizeof(t_img_cub)
			* NB_ANIMATION_FRAMES + 1);
	if (textures->text_bubbles == NULL)
		return (1);
	while (i < NB_ANIMATION_FRAMES)
	{
		textures->text_bubbles[i] = init_bubble(i, mlx);
		if (textures->text_bubbles[i] == NULL)
		{
			ft_printf_fd(2, BRED"Error\n"RESET"File `./textures/bubbles"
				" bubble_%d` seems to be corrupted\n", i);
			ret = 1;
			break ;
		}
		i++;
	}
	textures->text_bubbles[i] = NULL;
	return (ret);
}
