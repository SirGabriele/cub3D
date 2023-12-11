/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bubbles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:59:02 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/24 17:59:02 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_bubbles(t_img_cub **text_bubbles, t_img_cub *screen)
{
	static int	frame = 0;
	int			y;
	int			x;
	int			colour;

	y = 0;
	while (y < WIN_H)
	{
		x = 900;
		while (x < WIN_W)
		{
			if (frame == NB_ANIMATION_FRAMES)
				frame = 0;
			colour = get_pixel(text_bubbles[frame], x, y);
			if (colour == WHITE)
				my_mlx_pixel_put(screen, x, y, colour);
			x++;
		}
		y++;
	}
	frame++;
}
