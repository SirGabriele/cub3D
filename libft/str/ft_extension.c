/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:39:14 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/15 18:02:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_extension(const char *filename, const char *extension)
{
	int	filename_len;
	int	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len <= extension_len)
		return (1);
	if (ft_strcmp(filename + (filename_len - extension_len), extension) != 0)
		return (1);
	return (0);
}
