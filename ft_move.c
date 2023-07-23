/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:19:28 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/23 17:19:27 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_vars *vars)
{
	ft_free_map(vars->map);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_move_up(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y - 1][player.x] != '1')
	{
		if (map[player.y - 1][player.x] == 'C')
		{
			(*vars.count)--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
		}
		if (map[player.y - 1][player.x] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.y--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");

		}
		else if (map[player.y - 1][player.x] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}

void	ft_move_down(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y + 1][player.x] != '1')
	{
		if (map[player.y + 1][player.x] == 'C')
		{
			(*vars.count)--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
		}
		if (map[player.y + 1][player.x] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.y++;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		else if (map[player.y + 1][player.x] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}

void	ft_move_right(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x + 1] != '1')
	{
		if (map[player.y][player.x + 1] == 'C')
		{
			(*vars.count)--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
		}
		if (map[player.y][player.x + 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.x++;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		else if (map[player.y][player.x + 1] == 'E' && *vars.count == 0)
		{
			fprintf(stderr, "entre dans la fin\n");
			exit_hook(&vars);
		}
	}
}

void	ft_move_left(t_vars vars,t_pos player,  char **map)
{
	if (map[player.y][player.x - 1] != '1')
	{
		if (map[player.y][player.x - 1] == 'C')
		{
			(*vars.count)--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
		}
		if (map[player.y][player.x - 1] != 'E' && *vars.count >= 0)
		{
			map[player.y][player.x] = '0';
			ft_images(vars, player, "./images/back.xpm");
			player.x--;
			(*vars.nb_move)++;
			fprintf(stderr, "Nombre move : %d\n", *vars.nb_move);
			map[player.y][player.x] = 'P';
			ft_images(vars, player, "./images/player.xpm");
		}
		else if (map[player.y][player.x -1] == 'E' && *vars.count == 0)
			exit_hook(&vars);
	}
}
