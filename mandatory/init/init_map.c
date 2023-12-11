/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:07 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map_cub	*init_map(void)
{
	t_map_cub	*map;

	map = malloc(sizeof(t_map_cub));
	if (map == NULL)
		return (NULL);
	map->matrix = NULL;
	map->size_y = 0;
	map->size_x = 0;
	return (map);
}
