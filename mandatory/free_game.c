/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:42 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:43:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_frame(t_img_cub *frame, t_mlx_cub *mlx)
{
	if (frame->img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, frame->img);
	free(frame);
}

void	free_frame_arr(t_img_cub **arr, t_mlx_cub *mlx)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free_frame(arr[i], mlx);
		i++;
	}
	free(arr);
}

static void	free_textures(t_textures_cub *textures, t_mlx_cub *mlx)
{
	int	i;

	i = 0;
	if (textures->text_walls != NULL)
	{
		free_frame_arr(textures->text_walls, mlx);
		textures->text_walls = NULL;
	}
	free_double_arr(textures->text_floor);
	free_double_arr(textures->text_ceiling);
	free(textures);
}

static void	free_map(t_map_cub *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map->matrix != NULL && map->matrix[i] != NULL)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	if (map->matrix != NULL)
	{
		free(map->matrix);
		map->matrix = NULL;
	}
	free(map);
}

void	free_game(t_game_cub *game)
{
	if (game == NULL)
		return ;
	if (game->map != NULL)
		free_map(game->map);
	if (game->textures != NULL)
		free_textures(game->textures, game->mlx);
	if (game->math != NULL)
		free(game->math);
	if (game->mlx != NULL)
		free_mlx(game->mlx);
	free(game);
}
