/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:56:34 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	initialize_textures(t_textures_cub *textures, char **temp_textures)
{
	textures->text_floor = ft_split_char(temp_textures[F], ',');
	textures->text_ceiling = ft_split_char(temp_textures[C], ',');
	if (textures->text_floor == NULL || textures->text_ceiling == NULL)
		return (1);
	textures->text_floor_int[0] = ft_atoi(textures->text_floor[0]);
	textures->text_floor_int[1] = ft_atoi(textures->text_floor[1]);
	textures->text_floor_int[2] = ft_atoi(textures->text_floor[2]);
	textures->text_ceiling_int[0] = ft_atoi(textures->text_ceiling[0]);
	textures->text_ceiling_int[1] = ft_atoi(textures->text_ceiling[1]);
	textures->text_ceiling_int[2] = ft_atoi(textures->text_ceiling[2]);
	return (0);
}
