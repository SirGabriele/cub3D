/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:55 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_nb_carac_blocs(const char *file_line, const char **splitted)
{
	int	count;

	count = 0;
	while (splitted[count] != NULL)
		count++;
	if (count != 2)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET);
		if (count < 2)
			ft_putstr_fd(2, "Missing");
		else if (count > 2)
			ft_putstr_fd(2, "Too much");
		ft_printf_fd(2, " information on line:\n%s\n", file_line);
	}
	return (count);
}

int	is_line_valid(const char **splitted, t_keys_cub keys, const char **textures,
	const char *file_line)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	j = get_index_element(splitted, keys, file_line);
	if (j == NB_TEXTURES)
		ret = 1;
	else if (count_nb_carac_blocs(file_line, splitted) != 2)
		ret = 1;
	else if (textures[j] != NULL)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"'%s' element is declared twice\n",
			keys.keys[j]);
		ret = 1;
	}
	return (ret);
}
