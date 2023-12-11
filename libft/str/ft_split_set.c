/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:20:47 by kbrousse          #+#    #+#             */
/*   Updated: 2022/04/07 17:18:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	howmanycells(char const *str, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (is_in_set(str[i], set) == 0)
			i++;
		while (is_in_set(str[i], set) != 0)
			i++;
		count++;
		while (is_in_set(str[i], set) == 0)
			i++;
	}
	return (count);
}

static char	**fill_arr(char const *str, char *set, int nb_cells, char **arr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < nb_cells)
	{
		while (is_in_set(*str, set) == 0 && str[i] != '\0')
			str++;
		while (is_in_set(str[i], set) != 0 && str[i] != '\0')
			i++;
		arr[j] = malloc(sizeof(char) * i + 1);
		if (arr[j] == NULL)
		{
			free_double_arr(arr);
			return (NULL);
		}
		arr[j] = ft_strncpy(arr[j], (char *)str, i);
		str = &str[i];
		i = 0;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split_set(char const *str, char *set)
{
	char	**arr;
	int		nb_cells;

	arr = NULL;
	if (!str || !set)
		return (NULL);
	nb_cells = howmanycells(str, set);
	arr = malloc(sizeof(char *) * (nb_cells + 1));
	if (arr == NULL)
		return (NULL);
	fill_arr(str, set, nb_cells, arr);
	return (arr);
}
