/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depthsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:31:31 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 22:05:28 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sizemap	ft_rows_cols_map(char **map)
{
	t_sizemap	sizemap;

	sizemap.rows = ft_len_not_newline(map[0]);
	sizemap.cols = count_element_tab(map);
	return (sizemap);
}

void	ft_init_poz(t_pos *poz)
{
	poz->x = -1;
	poz->y = -1;
}

t_pos	ft_find_pos_player(char **map)
{
	t_sizemap	sizemap;
	t_pos		poz;
	int			y;
	int			x;

	y = 0;
	x = 0;
	ft_init_poz(&poz);
	sizemap = ft_rows_cols_map(map);
	while (y < sizemap.cols)
	{
		while (x < sizemap.rows)
		{
			if (map[y][x] == 'P')
			{
				poz.y = y;
				poz.x = x;
				return (poz);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (poz);
}

int	ft_is_valid(int px, int py, char **map)
{
	t_sizemap	sizemap;

	sizemap = ft_rows_cols_map(map);
	if (px < 0 || px >= sizemap.rows || py < 0 || py >= sizemap.cols)
		return (FAIL);
	if (map[py][px] == '1')
		return (FAIL);
	if (map[py][px] == 'E')
	{
		map[py][px] = 'X';
		return (FAIL);
	}
	return (SUCCESS);
}

int	ft_dfs(int y, int x, char **map)
{
	t_axe	axes;
	int		i;
	int		px;
	int		py;

	i = 0;
	axes = ft_init_axe();
	if (map[y][x] == '1')
		return (FAIL);
	map[y][x] = 'X';
	while (i < 4)
	{
		py = y + axes.dy[i];
		px = x + axes.dx[i];
		if (ft_is_valid(px, py, map) == 0 && map[py][px] != 'X')
		{
			if (ft_dfs(py, px, map) == 0)
				return (free(axes.dx), free(axes.dy), SUCCESS);
		}
		i++;
	}
	return (free(axes.dx), free(axes.dy), FAIL);
}
