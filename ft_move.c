/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:19:28 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/19 22:45:05 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y - 1][player.x] != '1')
	{
		if (map[player.y - 1][player.x] == 'C')
		{
			(*vars.count)--;
			fprintf(stderr, "Entre ici %d\n", *vars.count);
		}
		if (map[player.y][player.x - 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.y--;
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		if (map[player.y - 1][player.x] == 'E' && *vars.count == 0)
			fprintf(stderr, "EXIT");
	}
}

void	ft_move_down(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y + 1][player.x] != '1')
	{
		if (map[player.y + 1][player.x] == 'C')
		{
			(*vars.count)--;
			fprintf(stderr, "Entre ici %d\n", *vars.count);
		}
		if (map[player.y + 1][player.x] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.y++;
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		if (map[player.y + 1][player.x] == 'E' && *vars.count == 0)
			fprintf(stderr, "EXIT\n");
	}
}

void	ft_move_right(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x + 1] != '1')
	{
		if (map[player.y][player.x + 1] == 'C')
		{
			(*vars.count)--;
			fprintf(stderr, "Entre ici %d\n", *vars.count);
		}
		if (map[player.y][player.x + 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.x++;
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		if (map[player.y][player.x + 1] == 'E' && *vars.count == 0)
			fprintf(stderr, "EXIT");
	}
}

void	ft_move_left(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x - 1] != '1')
	{
		if (map[player.y][player.x - 1] == 'C')
		{
			(*vars.count)--;
			fprintf(stderr, "Entre ici %d\n", *vars.count);
		}
		if (map[player.y][player.x - 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.x--;
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		if (map[player.y][player.x - 1] == 'E' && *vars.count == 0)
			fprintf(stderr, "EXIT");
	}
}

// ToDO
/*


*/