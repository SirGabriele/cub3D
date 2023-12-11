/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:02 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	close_file(int file_fd, const char *file_path)
{
	int	ret;

	ret = close(file_fd);
	if (ret < 0)
	{
		if (file_path != NULL)
			ft_printf_fd(2, BRED"Error\n"RESET"Failed to close '%s'\n",
				file_path);
	}
	return (ret);
}

int	open_o_rdonly(const char *file_path)
{
	int	file_fd;

	file_fd = open(file_path, O_RDONLY);
	if (file_fd < 0)
	{
		if (file_path != NULL)
			ft_printf_fd(2, BRED"Error\n"RESET"Failed to open '%s'\n",
				file_path);
	}
	return (file_fd);
}
