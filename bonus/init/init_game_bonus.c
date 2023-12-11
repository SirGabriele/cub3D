/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:07 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:54:55 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_game_cub	*init_game(const char *file_path)
{
	t_game_cub	*game;

	game = malloc(sizeof(t_game_cub));
	if (game == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	game->map = NULL;
	game->mlx = NULL;
	game->textures = NULL;
	game->file_path = file_path;
	game->minimap_zoom = 10;
	game->minimap_ratio_y = (float)MINMAP_H / (game->minimap_zoom * 2 + 1);
	game->minimap_ratio_x = (float)MINMAP_W / (game->minimap_zoom * 2 + 1);
	game->math = malloc(sizeof(t_math_cub));
	if (game->math == NULL)
	{
		free(game);
		perror(NULL);
		return (NULL);
	}
	return (game);
}
