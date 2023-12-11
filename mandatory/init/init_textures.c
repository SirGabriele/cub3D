/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:44:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_textures_cub	*init_textures(void)
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
	return (textures);
}
