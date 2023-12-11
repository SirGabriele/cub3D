/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:58:08 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	set_starting_pos(t_game_cub *game, int row, int column)
{
	if (game->math->p_x != 0 || game->math->p_y != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map can only contain one"
			" starting point for the player\n");
		return (1);
	}
	game->math->p_y = row + 0.5;
	game->math->p_x = column + 0.5;
	game->spawn_dir = game->map->matrix[row][column];
	game->map->matrix[row][column] = '0';
	ft_init_math_value(game, game->math);
	return (0);
}

int	get_player_pos(t_game_cub *game, const char **matrix)
{
	int	i;
	int	j;

	i = 0;
	game->math->p_x = 0;
	game->math->p_y = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (j < game->map->size_y)
		{
			if (is_char_in_set(matrix[i][j], "NSWE") == 0
				&& set_starting_pos(game, i, j) != 0)
				return (1);
			j++;
		}
		i++;
	}
	if (game->math->p_x == 0 || game->math->p_y == 0)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"The map must contain one starting"
			" point for the player\n");
		return (1);
	}
	return (0);
}
