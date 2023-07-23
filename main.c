/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/23 18:46:44 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_map_check(char **map)
{
	t_pos player;
	t_sizemap cordo;

	cordo = ft_rows_cols_map(map);
	if (is_rectangle(map) == 1)
		return (FAIL);
	ft_valid_wall_perimeter(map);
	if (ft_nb_elmts(cordo.cols, cordo.rows, map) == 1)
		return (FAIL);
	if (ft_elements_valid(cordo.cols, cordo.rows, map) == 1)
		return (FAIL);
	player = ft_find_pos_player(map);
	ft_dfs(player.y, player.x, map);
	if (ft_find_elemt_dfs(cordo.cols, cordo.rows, map) == 1)
		return (FAIL);
	return (0);
}

int key_hook(int keycode, t_vars *vars)
{
	t_pos player;

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

int	main(int argc, char *argv[])
{
	int			fd2;
	int	fd;
	char		**map;
	t_sizemap	cordo;
	t_vars		vars;
	int			nb_collect;
	int			nb_move;
	int			size;

	nb_move = 0;
	size = 0;
	if (argc == 2)
	{
		// size = ft_size_tab_init(argv[1]);
		if (ft_endswith(argv[1]) == 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		size = nb_line(fd);
		if (size == 1)

			return (close(fd), 0);
		close(fd);
		fd2 = open(argv[1], O_RDONLY);
		if (fd2 == -1)
		{
			close(fd2);
			perror("open");
			exit(EXIT_FAILURE);
		}
		map = tab_line(fd2, size);
		cordo = ft_rows_cols_map(map);
		vars.map = ft_copy_array(map, cordo);
		if (ft_map_check(map) == FAIL)
		{
			ft_free_map(map);
			ft_free_map(vars.map);
			return (FAIL);
		}
		ft_free_map(map);
		cordo = ft_rows_cols_map(vars.map);
		// ft_free_map(map);
		nb_collect = ft_nb_collect(cordo.cols, cordo.rows, vars.map);
		vars.count = &nb_collect;
		vars.nb_move = &nb_move;

		/* ===> Minilibx <=== */
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1900, 1000, "So long");
		ft_display_sprite(cordo, vars, vars.map);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 1L << 17, exit_hook, &vars);
		mlx_loop(vars.mlx);
		mlx_clear_window(vars.mlx, vars.win);
		mlx_destroy_window(vars.mlx, vars.win);
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	return (0);
}

// TODO :
/*
=> tester la taille de chaque ligne
*/