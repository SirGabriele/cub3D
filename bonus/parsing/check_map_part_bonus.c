/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_part_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:56:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	copy_line_into_matrix(char *matrix, const char *file_line,
	int size_y)
{
	int	i;

	i = 0;
	while (file_line[i] != '\0' && file_line[i] != '\n')
	{
		matrix[i] = file_line[i];
		i++;
	}
	while (i <= size_y)
	{
		matrix[i] = '\0';
		i++;
	}
	return (0);
}

static int	extract_map_into_matrix(const char *file_path, t_map_cub *map)
{
	char	*file_line;
	int		file_fd;
	int		i;

	file_fd = open_o_rdonly(file_path);
	if (file_fd < 0)
		return (1);
	i = 0;
	file_line = get_first_map_line(file_fd);
	while (file_line != NULL && is_line_empty(file_line) != 0)
	{
		copy_line_into_matrix(map->matrix[i], file_line, map->size_y);
		free(file_line);
		file_line = get_next_line(file_fd);
		i++;
	}
	map->matrix[i] = NULL;
	read_file_to_the_end(file_fd, file_line);
	if (close_file(file_fd, file_path) != 0)
		return (1);
	return (0);
}

int	check_map_part(t_game_cub *game)
{
	int	file_fd;
	int	ret;

	ret = 0;
	game->map = init_map();
	if (game->map == NULL || get_map_infos(game->file_path, game->map) != 0)
		return (1);
	game->map->matrix = init_matrix(game->map->size_y, game->map->size_x);
	if (game->map->matrix == NULL)
		return (1);
	else if (extract_map_into_matrix(game->file_path, game->map) != 0
		|| get_player_pos(game, (const char **)game->map->matrix) != 0)
		return (1);
	file_fd = open_o_rdonly(game->file_path);
	if (file_fd < 0)
		return (1);
	if (are_boundaries_closed((const char **)game->map->matrix,
			game->map->size_x, game->map->size_y) != 0
		|| fill_matrix_holes(game->map->matrix, game->map->size_y) != 0)
		ret = 1;
	if (close_file(file_fd, game->file_path) != 0 || ret == 1)
		return (1);
	return (0);
}
