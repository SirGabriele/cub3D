/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_validity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	verify_rgb(const char *texture)
{
	char	**splitted;
	int		count;
	int		ret;

	ret = 0;
	count = 0;
	splitted = ft_split_char(texture, ',');
	if (splitted == NULL)
	{
		perror(NULL);
		return (1);
	}
	while (splitted[count] != NULL)
		count++;
	if (count != 3 || is_rgb_valid(texture) != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Correct format for F and C"
			" elements is:\n[F/C] [0,255],[0,255],[0,255]\n");
		ret = 1;
	}
	free_double_arr(splitted);
	return (ret);
}

static int	verify_texture_path(const char *texture)
{
	int			texture_fd;
	int			ret;

	ret = 0;
	texture_fd = open_o_rdonly(texture);
	if (texture_fd < 0)
		ret = 1;
	else if (close_file(texture_fd, texture) != 0)
		ret = 1;
	return (ret);
}

static int	are_all_elements_valid(const char **textures)
{
	int	i;

	i = 0;
	while (i < F)
	{
		if (verify_texture_path(textures[i]) != 0)
			return (1);
		i++;
	}
	while (i < NB_TEXTURES)
	{
		if (verify_rgb(textures[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	are_all_elements_collected(const char **textures)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		if (textures[i] == NULL)
		{
			ft_putstr_fd(2, BRED"Error\n"RESET"Missing elements in map\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_elements_validity(const char **textures)
{
	if (are_all_elements_collected(textures) != 0
		|| are_all_elements_valid(textures) != 0)
		return (1);
	return (0);
}
