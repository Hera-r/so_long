/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:16:31 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/25 20:52:58 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_second_fd(char *filename)
{
	int	fd2;

	fd2 = open(filename, O_RDONLY);
	if (fd2 == -1)
	{
		close(fd2);
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd2);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_pos	player;

	player = ft_find_pos_player(vars->map);
	if (keycode == 'w')
		ft_move_up(*vars, player, vars->map);
	if (keycode == 's')
		ft_move_down(*vars, player, vars->map);
	if (keycode == 'd')
		ft_move_right(*vars, player, vars->map);
	if (keycode == 'a')
		ft_move_left(*vars, player, vars->map);
	if (keycode == XK_ESCAPE)
		return (exit_hook(vars), SUCCESS);
	return (SUCCESS);
}

int	ft_launch_game(t_vars *vars, t_sizemap cordo)
{
	ft_display_sprite(cordo, *vars, vars->map);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, exit_hook, vars);
	mlx_loop(vars->mlx);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (SUCCESS);
}

int	ft_game(char **map)
{
	t_sizemap	cordo;
	t_vars		vars;
	int			nb_move;
	int			nb_collect;

	nb_move = 0;
	vars.map = map;
	cordo = ft_rows_cols_map(vars.map);
	nb_collect = ft_nb_collect(cordo.cols, cordo.rows, vars.map);
	vars.count = &nb_collect;
	vars.nb_move = &nb_move;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (FAIL);
	if (ft_all_img(&vars) == 1)
		return (ft_destroy_img(&vars), mlx_destroy_display(vars.mlx),
			free(vars.mlx), FAIL);
	vars.win = mlx_new_window(vars.mlx, cordo.rows * 43, \
		cordo.cols * 50, "So long");
	if (vars.win == NULL)
		return (ft_destroy_img(&vars), mlx_destroy_display(vars.mlx),
			free(vars.mlx), FAIL);
	return (ft_launch_game(&vars, cordo));
}

int	ft_the_game(char **map_cpy)
{
	if (ft_game(map_cpy) == FAIL)
	{
		ft_free_map(map_cpy);
		ft_printf("Error\nProblem : mlx init or window creation\n");
		return (FAIL);
	}
	return (0);
}
