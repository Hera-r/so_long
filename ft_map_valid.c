/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:58:53 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/26 13:15:20 by hrandria         ###   ########.fr       */
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
				ft_printf("Error\nNot acces (C, P, E)\n");
				return (FAIL);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (SUCCESS);
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
			if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x]
				!= 'P' && map[y][x] != 'E' && map[y][x] != '0')
			{
				ft_printf("Error\nElement not valid\n");
				return (FAIL);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (SUCCESS);
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
	t_elements	elemts;

	elemts = ft_count_elements(cols, rows, map);
	if (elemts.c <= 0)
	{
		ft_printf("Error\nItem not found\n");
		return (FAIL);
	}
	else if (elemts.p > 1 || elemts.p == 0)
	{
		ft_printf("Error\nPlayer not found or more than one\n");
		return (FAIL);
	}
	else if (elemts.e > 1 || elemts.e == 0)
	{
		ft_printf("Error\nExit not found or more than one\n");
		return (FAIL);
	}
	return (SUCCESS);
}
