/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:19:28 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 22:26:44 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_vars *vars)
{
	ft_free_map(vars->map);
	ft_destroy_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_move_up(t_vars vars, t_pos player, char **map)
{
	if (map[player.y - 1][player.x] != '1')
	{
		if (map[player.y - 1][player.x] == 'C')
		{
			(*vars.count)--;
			(*vars.nb_move)++;
			ft_printf("Nombre move : %d\n", *vars.nb_move);
		}
		if (map[player.y - 1][player.x] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, vars.back);
			player.y--;
			(*vars.nb_move)++;
			ft_printf("Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, vars.player);
		}
		else if (map[player.y - 1][player.x] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}

void	ft_move_down(t_vars vars, t_pos player, char **map)
{
	if (map[player.y + 1][player.x] != '1')
	{
		if (map[player.y + 1][player.x] == 'C')
			(*vars.count)--;
		if (map[player.y + 1][player.x] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, vars.back);
			player.y++;
			(*vars.nb_move)++;
			ft_printf("Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, vars.player);
		}
		else if (map[player.y + 1][player.x] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}

void	ft_move_right(t_vars vars, t_pos player, char **map)
{
	if (map[player.y][player.x + 1] != '1')
	{
		if (map[player.y][player.x + 1] == 'C')
			(*vars.count)--;
		if (map[player.y][player.x + 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, vars.back);
			player.x++;
			(*vars.nb_move)++;
			ft_printf("Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, vars.player);
		}
		else if (map[player.y][player.x + 1] == 'E' && *vars.count == 0)
		{
			exit_hook(&vars);
		}
	}
}

void	ft_move_left(t_vars vars, t_pos player, char **map)
{
	if (map[player.y][player.x - 1] != '1')
	{
		if (map[player.y][player.x - 1] == 'C')
			(*vars.count)--;
		if (map[player.y][player.x - 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, vars.back);
			player.x--;
			(*vars.nb_move)++;
			ft_printf("Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, vars.player);
		}
		else if (map[player.y][player.x -1] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}
