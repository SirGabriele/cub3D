/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_coord_colour_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:24:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 15:44:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	get_matrix_coord_colour(t_game_cub *game, int pixel_x, int pixel_y)
{
	float	column;
	float	row;
	float	minimap_y;
	float	minimap_x;
	int		len_line;

	minimap_y = (pixel_y / game->minimap_ratio_y) - game->minimap_zoom;
	minimap_x = (pixel_x / game->minimap_ratio_x) - game->minimap_zoom;
	row = game->math->p_y + minimap_y - 0.5;
	column = game->math->p_x + minimap_x - 0.5;
	if ((int)row < 0 || (int)row > game->map->size_x - 1)
		return (convert_rgb_into_int(game->textures->text_ceiling_int));
	len_line = ft_strlen(game->map->matrix[(int)row]);
	if ((int)column < 0 || (int)column > len_line)
		return (convert_rgb_into_int(game->textures->text_ceiling_int));
	else if ((int)row == 0 || (int)row == game->map->size_x - 1
		|| (int)column == 0 || (int)column == len_line)
		return (convert_rgb_into_int(game->textures->text_ceiling_int));
	if (game->map->matrix[(int)row][(int)column] == '1')
		return (convert_rgb_into_int(game->textures->text_ceiling_int));
	else if (game->map->matrix[(int)row][(int)column] == 'C')
		return (BROWN);
	else if (game->map->matrix[(int)row][(int)column] == 'O')
		return (PURPLE);
	return (convert_rgb_into_int(game->textures->text_floor_int));
}
