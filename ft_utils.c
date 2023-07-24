/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:42:14 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 22:41:14 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_line(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = get_next_line(fd);
	i++;
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	return (i);
}

char	**tab_line(int fd, int size)
{
	int		i;
	char	**tab;
	char	*str;

	i = 1;
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	str = get_next_line(fd);
	tab[0] = str;
	while (str)
	{
		str = get_next_line(fd);
		tab[i] = str;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	ft_endswith(char *filename)
{
	char	*str;
	int		len;

	str = ".ber";
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + (len - 4), str, 4) != 0)
	{
		ft_printf("Error\nextension\n");
		return (1);
	}
	return (0);
}

int	ft_nb_collect(int cols, int rows, char **map)
{
	int	y;
	int	x;
	int	count;

	y = 1;
	x = 0;
	count = 0;
	while (y < cols)
	{
		while (x < rows)
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}
