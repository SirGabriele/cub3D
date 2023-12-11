/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:07 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:54:30 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	free_before_returning_null(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**init_matrix(int size_y, int size_x)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = malloc(sizeof(char *) * (size_x + 1));
	if (matrix == NULL)
		return (NULL);
	while (i < size_x)
	{
		matrix[i] = malloc(sizeof(char) * (size_y + 1));
		if (matrix[i] == NULL)
		{
			free_before_returning_null(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
