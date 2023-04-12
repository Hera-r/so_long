/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depthsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:31:31 by hrandria          #+#    #+#             */
/*   Updated: 2023/04/12 16:42:42 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sizemap	ft_rows_cols_map(char **map)
{
	t_sizemap	size_map;

	size_map.rows = ft_len_not_newline(map[0]);
	size_map.cols = count_element_tab(map);
	return (size_map);
}

t_pos	ft_find_pos_player(char **map)
{
	t_sizemap sizemap;
	t_pos		pos;
	int			i;
	int			j;

	i = 0;
	j = 0;
	sizemap = ft_rows_cols_map(map);
	while (i < sizemap.cols)
	{
		while (j < sizemap.rows)
		{
			if (map[i][j] == 'P')
			{
				pos.y = i;
				pos.x = j;
				return (pos);
			}
		j++;
		}
	i++;
	j = 0;
	}
	return (pos);
}

int ft_is_valid(int x, int y, char **map)
{
	t_sizemap sizemap;

	sizemap = ft_rows_cols_map(map);
	if (x < 0 || x >= sizemap.rows || y < 0 || y >= sizemap.cols)
		return (1);
	return (0);
}

int	ft_dfs(int x, int y, char **map)
{
	int	cols;
	int	i;
	int	px;
	int	py;
	int	dx[4] = {0, 1, 0, -1};
	int	dy[4] = {-1, 0, 1, 0};

	cols = count_element_tab(map);
	if (map[y][x] == 'C')
		return (0);

	map[y][x] = 'X';
	while (i < cols)
	{
		px = x + dx[i];
		py = y + dy[i];
		if (ft_dfs(px, py, map) && ft_is_valid(px, py, map) != 1)
			return (0);
	i++;
	}
	return (1);
}
