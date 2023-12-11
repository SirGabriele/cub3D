/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_the_end_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:10 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:58:11 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	read_file_to_the_end(int file_fd, char *file_line)
{
	free(file_line);
	file_line = get_next_line(file_fd);
	while (file_line != NULL)
	{
		free(file_line);
		file_line = get_next_line(file_fd);
	}
}
