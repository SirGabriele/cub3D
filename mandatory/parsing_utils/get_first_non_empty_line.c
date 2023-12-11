/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_non_empty_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:23 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_first_non_empty_line(int file_fd)
{
	char		*file_line;

	file_line = get_next_line(file_fd);
	if (file_line == NULL)
		return (NULL);
	while (file_line != NULL && is_line_empty(file_line) == 0)
	{
		free(file_line);
		file_line = get_next_line(file_fd);
	}
	return (file_line);
}
