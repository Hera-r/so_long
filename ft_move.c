/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:19:28 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/15 20:32:09 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y - 1][player.x] != '1')
	{
		map[player.y][player.x] = '0';
		ft_images(vars, player, "./images/back.xpm");
		player.y--;
		map[player.y][player.x] = 'P';
		ft_images(vars, player, "./images/player.xpm");
	}
}

void	ft_move_down(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y + 1][player.x] != '1')
	{
		map[player.y][player.x] = '0';
		ft_images(vars, player, "./images/back.xpm");
		player.y++;
		map[player.y][player.x] = 'P';
		ft_images(vars, player, "./images/player.xpm");
	}
}

void	ft_move_right(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x + 1] != '1')
	{
		map[player.y][player.x] = '0';
		ft_images(vars, player, "./images/back.xpm");
		player.x++;
		map[player.y][player.x] = 'P';
		ft_images(vars, player, "./images/player.xpm");
	}
}

void	ft_move_left(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x - 1] != '1')
	{
		map[player.y][player.x] = '0';
		ft_images(vars, player, "./images/back.xpm");
		player.x--;
		map[player.y][player.x] = 'P';
		ft_images(vars, player, "./images/player.xpm");
	}
}