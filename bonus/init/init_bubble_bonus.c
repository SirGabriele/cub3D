/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bubble_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:55 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:31 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_img_cub	*init_bubble(int i, t_mlx_cub *mlx)
{
	t_img_cub	*bubble;
	char		*number;
	char		*path;

	number = ft_itoa(i);
	if (number == NULL)
		return (NULL);
	path = ft_strjoin_free_second("./textures/bubbles/bubble_", number);
	if (path == NULL)
		return (NULL);
	path = ft_strjoin_free_first(path, ".xpm");
	if (path == NULL)
		return (NULL);
	bubble = init_frame(path, mlx);
	if (bubble == NULL)
	{
		free(path);
		perror(NULL);
		return (NULL);
	}
	free(path);
	return (bubble);
}
