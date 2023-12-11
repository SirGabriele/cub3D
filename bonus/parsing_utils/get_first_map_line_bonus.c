/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_map_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:20 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	*get_first_map_line(int file_fd)
{
	char	*file_line;
	int		line;

	line = 0;
	file_line = get_first_non_empty_line(file_fd);
	while (file_line != NULL && line < NB_TEXTURES)
	{
		free(file_line);
		file_line = get_first_non_empty_line(file_fd);
		line++;
	}
	if (file_line == NULL)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"No map is provided in this file\n");
		return (NULL);
	}
	return (file_line);
}
