/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_infos_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:57:27 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:28 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	calculate_dimensions(int file_fd, t_map_cub *map)
{
	char	*file_line;
	int		current_length;
	int		ret;

	ret = 0;
	file_line = get_first_map_line(file_fd);
	if (file_line == NULL)
		return (1);
	map->size_x = 1;
	map->size_y = ft_strlen_no_newline(file_line);
	while (file_line != NULL)
	{
		free(file_line);
		file_line = get_next_line(file_fd);
		if (file_line == NULL || is_line_empty(file_line) == 0)
			break ;
		map->size_x++;
		current_length = ft_strlen_no_newline(file_line);
		if (current_length > map->size_y)
			map->size_y = current_length;
	}
	read_file_to_the_end(file_fd, file_line);
	return (ret);
}

static int	detect_forbidden_character(int file_fd)
{
	char	*file_line;
	int		ret;

	ret = 0;
	file_line = get_first_map_line(file_fd);
	if (file_line == NULL)
		return (1);
	while (file_line != NULL)
	{
		if (is_there_forbidden_char(file_line, ALLOWED_MAP_CHARSET) == 0)
		{
			ft_printf_fd(2, BRED"Error\n"RESET"Forbidden character on line:\n%s\n",
				file_line);
			ret = 1;
			break ;
		}
		free(file_line);
		file_line = get_next_line(file_fd);
	}
	if (ret != 1 && is_file_finished(file_fd) != 0)
		ret = 1;
	read_file_to_the_end(file_fd, file_line);
	return (ret);
}

int	get_map_infos(const char *file_path, t_map_cub *map)
{
	int	file_fd;
	int	ret;

	ret = 0;
	file_fd = open_o_rdonly(file_path);
	if (file_fd < 0)
		return (1);
	if (detect_forbidden_character(file_fd) != 0)
		ret = 1;
	if (close_file(file_fd, file_path) != 0 || ret == 1)
		return (1);
	file_fd = open_o_rdonly(file_path);
	if (file_fd < 0)
		return (1);
	if (calculate_dimensions(file_fd, map) != 0)
		ret = 1;
	if (close_file(file_fd, file_path) != 0 || ret == 1)
		return (1);
	return (0);
}
