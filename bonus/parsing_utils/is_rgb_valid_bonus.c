/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:57 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:58 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	are_values_in_range(const char *texture)
{
	char	**splitted;
	int		i;
	int		converted;

	i = 0;
	splitted = ft_split_char(texture, ',');
	if (splitted == NULL)
	{
		perror(NULL);
		return (1);
	}
	while (splitted[i] != NULL)
	{
		converted = ft_atoi(splitted[i]);
		if (is_an_int(splitted[i]) != 0
			|| converted < 0
			|| converted > 255)
		{
			free_double_arr(splitted);
			return (1);
		}
		i++;
	}
	free_double_arr(splitted);
	return (0);
}

static int	count_nb_commas(const char *texture)
{
	int	i;
	int	count;

	i = 0;
	if (texture[i] == ',')
		return (1);
	while (texture[i] != '\0')
	{
		count = 0;
		while (texture[i + count] == ',')
			count++;
		if (count > 1)
			return (1);
		i++;
	}
	if (texture[i - 1] == ',')
		return (1);
	return (0);
}

int	is_rgb_valid(const char *texture)
{
	if (is_there_forbidden_char(texture, "0123456789,") == 0
		|| count_nb_commas(texture) != 0
		|| are_values_in_range(texture) != 0)
		return (1);
	return (0);
}
