/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_an_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:44:01 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/21 17:44:45 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_an_int(char *arr)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (((*arr >= 9 && *arr <= 13) || *arr == 32) && *arr != '\0')
			arr++;
	if (*arr == '\0')
		return (1);
	if (*arr == '-' || *arr == '+')
	{
		sign = -sign;
		arr++;
	}
	while (*arr >= 48 && *arr <= 57)
	{
		res = res * 10 + (*arr - 48);
		arr++;
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			return (1);
	}
	return (0);
}
