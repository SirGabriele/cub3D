/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_no_newline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:24:17 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/27 14:24:21 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_no_newline(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*str != '\n' && *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
