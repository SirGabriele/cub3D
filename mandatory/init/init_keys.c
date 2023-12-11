/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:07 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:21 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_keys_cub	init_keys(void)
{
	t_keys_cub	keys;

	keys.keys[NO] = "NO";
	keys.keys[SO] = "SO";
	keys.keys[WE] = "WE";
	keys.keys[EA] = "EA";
	keys.keys[F] = "F";
	keys.keys[C] = "C";
	return (keys);
}
