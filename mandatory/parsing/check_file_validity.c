/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_file_empty(const char *file_path)
{
	char	*file_line;
	int		file_fd;

	file_fd = open_o_rdonly(file_path);
	if (file_fd < 0)
		return (0);
	file_line = get_first_non_empty_line(file_fd);
	if (file_line == NULL)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"File is empty\n");
		close_file(file_fd, file_path);
		return (0);
	}
	read_file_to_the_end(file_fd, file_line);
	if (close_file(file_fd, file_path) != 0)
		return (0);
	return (1);
}

static int	check_file_existence(const char *file_path)
{
	if (access(file_path, F_OK) != 0)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"File '%s' does not exist\n",
			file_path);
		return (1);
	}
	if (access(file_path, R_OK) != 0)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"File '%s' does not grant"
			" read permissions\n", file_path);
		return (1);
	}
	return (0);
}

int	check_file_validity(const char *file_path)
{
	if (ft_extension(file_path, FILE_EXT) != 0)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"Map file '%s' has incorrect"
			" extension. Expects "FILE_EXT" extension\n", file_path);
		return (1);
	}
	else if (check_file_existence(file_path) != 0
		|| is_file_empty(file_path) == 0)
		return (1);
	return (0);
}
