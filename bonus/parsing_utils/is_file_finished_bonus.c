/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_finished_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:32 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:32 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_file_finished(int file_fd)
{
	char	*file_line;

	file_line = get_first_non_empty_line(file_fd);
	if (file_line != NULL)
	{
		read_file_to_the_end(file_fd, file_line);
		ft_putstr_fd(2, BRED"Error\n"RESET"Map must:\n\t- be"
			" the last element of the file\n\t- not contain empty lines\n");
		return (1);
	}
	return (0);
}
