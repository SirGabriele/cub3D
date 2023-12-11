/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:25 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_index_element(const char **splitted, t_keys_cub keys,
	const char *file_line)
{
	int	index;

	index = 0;
	while (index < NB_TEXTURES && ft_strcmp(splitted[0], keys.keys[index]))
		index++;
	if (index == NB_TEXTURES)
		ft_printf_fd(2, BRED"Error\n"RESET"Incorrect information on line:\n%s\n",
			file_line);
	return (index);
}
