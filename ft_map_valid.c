/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:58:53 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/20 20:29:22 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_elemt_dfs(int cols, int rows, char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (y < cols)
	{
		while (x < rows)
		{
			if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
			{
				printf("Not acces (C, P, E)\n");
				return(1);
			}
		x++;
		}
	y++;
	x = 0;
	}
	return (0);
}

int	ft_elements_valid(int cols, int rows, char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (y < cols)
	{
		while (x < rows)
		{
			if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != '0')
			{
				printf("Element not valid\n");
				return (1);
			}
		x++;
		}
	y++;
	x = 0;
	}
	return (0);
}

t_elements	ft_count_elements(int cols, int rows, char **map)
{
    t_elements	nb_elmt;
    int			y;
    int			x;

	y = 1;
	x = 0;
	nb_elmt.c = 0;
	nb_elmt.e = 0;
	nb_elmt.p = 0;
	while (y < cols)
	{
		while (x < rows)
		{
			if (map[y][x] == 'C')
				nb_elmt.c++;
			if (map[y][x] == 'P')
				nb_elmt.p++;
			if (map[y][x] == 'E')
				nb_elmt.e++;
		x++;
		}
	y++;
	x = 0;
	}
	return (nb_elmt);
}

int	ft_nb_elmts(int cols, int rows, char **map)
{
	t_elements elemts;

	elemts = ft_count_elements(cols, rows, map);
	if (elemts.c <= 0)
	{
		printf("Item not found\n");
		return (1);
	}
	else if (elemts.p > 1 || elemts.p == 0)
	{
		printf("Player not found or superor 1\n");
		return (1);
	}
	else if (elemts.e > 1 || elemts.e == 0)
	{
		printf("Exit not found or superor 1\n");
		return (1);
	}
	return (0);
}
