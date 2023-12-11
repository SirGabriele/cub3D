/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:43 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:45:59 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	copy_element_values(t_textures_cub *textures, char **temp_textures,
	t_mlx_cub *mlx)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	textures->text_walls = malloc(sizeof(t_img_cub *) * NB_TEXTURES - 2 + 1);
	if (textures->text_walls == NULL)
		return (1);
	while (i < NB_TEXTURES - 2)
	{
		textures->text_walls[i] = init_frame(temp_textures[i], mlx);
		if (textures->text_walls[i] == NULL)
		{
			ft_printf_fd(2, BRED"Error\n"RESET"File `%s` seems to be corrupted\n",
				temp_textures[i]);
			ret = 1;
			break ;
		}
		i++;
	}
	textures->text_walls[i] = NULL;
	if (initialize_textures(textures, temp_textures) != 0)
		ret = 1;
	return (ret);
}

static int	extract_line_element(const char **splitted, t_keys_cub keys,
	char **temp_textures, const char *file_line)
{
	int		index;

	index = get_index_element(splitted, keys, file_line);
	if (index == NB_TEXTURES)
		return (1);
	temp_textures[index] = ft_strdup(splitted[1]);
	if (temp_textures[index] == NULL)
		return (1);
	return (0);
}

static int	analyse_line(const char *file_line, char **temp_textures)
{
	char		**splitted;
	t_keys_cub	keys;
	int			ret;

	ret = 0;
	splitted = ft_split_set(file_line, " \n");
	keys = init_keys();
	if (splitted == NULL || is_line_valid((const char **)splitted,
			keys, (const char **)temp_textures, file_line) != 0)
		ret = 1;
	else if (extract_line_element((const char **)splitted, keys,
			temp_textures, file_line) != 0)
		ret = 1;
	free_double_arr(splitted);
	return (ret);
}

static int	browse_and_extract_elements(int file_fd, char **temp_textures)
{
	char	*file_line;
	int		line;

	file_line = get_first_non_empty_line(file_fd);
	line = 0;
	while (file_line != NULL && line < NB_TEXTURES)
	{
		if (analyse_line(file_line, temp_textures) != 0)
		{
			read_file_to_the_end(file_fd, file_line);
			return (1);
		}
		free(file_line);
		file_line = get_first_non_empty_line(file_fd);
		line++;
	}
	read_file_to_the_end(file_fd, file_line);
	return (0);
}

int	check_element_part(t_game_cub *game)
{
	char	**temp_textures;
	int		file_fd;
	int		ret;

	ret = 0;
	file_fd = open_o_rdonly(game->file_path);
	if (file_fd < 0)
		return (1);
	temp_textures = ft_calloc(sizeof(char *), NB_TEXTURES + 1);
	game->mlx = init_mlx();
	if (game->mlx != NULL)
	game->textures = init_textures();
	if (temp_textures == NULL || game->textures == NULL || game->mlx == NULL)
		ret = 1;
	else if (browse_and_extract_elements(file_fd, temp_textures) != 0
		|| check_elements_validity((const char **)temp_textures) != 0
		|| copy_element_values(game->textures, temp_textures, game->mlx) != 0)
		ret = 1;
	if (temp_textures != NULL)
		free_temp_textures_arr(temp_textures);
	if (close_file(file_fd, game->file_path) != 0 || ret == 1)
		return (1);
	return (0);
}
