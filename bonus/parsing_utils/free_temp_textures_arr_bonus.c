/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_temp_textures_arr_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:17 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_temp_textures_arr(char **textures)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		if (textures[i] != NULL)
			free(textures[i]);
		i++;
	}
	free(textures);
}
