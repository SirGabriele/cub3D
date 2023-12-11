/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_diving_mask_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:59:04 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:59:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_diving_mask(t_img_cub *text_diving_mask, t_img_cub *screen)
{
	int	y;
	int	x;
	int	colour;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			colour = get_pixel(text_diving_mask, x, y);
			if (colour == GREY)
				my_mlx_pixel_put(screen, x, y, colour);
			x++;
		}
		y++;
	}
}
