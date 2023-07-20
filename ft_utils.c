/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:42:14 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/20 23:31:31 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_line(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (str[0] == '\n')
		{
			printf("Not valid map\n");
			return (1);
		}
		str = get_next_line(fd);
	i++;
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
	tab[i] = 0;
	return (tab);
}

int	ft_endswith(char *filename)
{
	char	*str;
	int		size;

	str = ".ber";
	size = ft_strlen(str);
	while (size)
	{
		if(filename[size] != str[size])
			return (1);
	size--;
	}
	return (0);
}

int	ft_nb_collect(int cols, int rows, char **map)
{
    int			y;
    int			x;
	int			count;

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