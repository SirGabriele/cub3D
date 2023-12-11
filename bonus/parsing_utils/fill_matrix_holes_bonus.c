/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_holes_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:08 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:14 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	fill_matrix_holes(char **matrix, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (j < size_y)
		{
			if (ft_isspace(matrix[i][j]) == 1 || matrix[i][j] == '\0')
				matrix[i][j] = '1';
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (0);
}
