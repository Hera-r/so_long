/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 00:53:51 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_check(char **map)
{
	t_pos player;
	t_sizemap cordo;

	cordo = ft_rows_cols_map(map);
	if (is_rectangle(map) == 1)
		return (FAIL);
	if (ft_valid_wall_perimeter(map) == FAIL)
		return (FAIL);
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
	vars.win = mlx_new_window(vars.mlx, 1900, 1000, "So long");
	if (vars.win == NULL)
		return (free(vars.mlx), FAIL);
	return(ft_launch_game(&vars, cordo));
}

int	main(int argc, char *argv[])
{
	int			fd2;
	int	fd;
	char		**map;
	char		**map_cpy;
	t_sizemap	cordo;
	int			size;

	size = 0;
	if (argc == 2)
	{
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
		map_cpy = ft_copy_array(map, cordo);
		if (ft_map_check(map) == FAIL)
			return (ft_free_map(map), ft_free_map(map_cpy), FAIL);
		ft_free_map(map);
		if (ft_game(map_cpy) == FAIL)
		{
			ft_free_map(map_cpy);
			printf("Problem : mlx init or window creation\n");
			return (FAIL);
		}
		ft_free_map(map_cpy);
	}
	return (0);
}
