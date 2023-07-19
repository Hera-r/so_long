/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/19 22:45:50 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(char **map)
{
	t_pos		player;
	t_sizemap	cordo;

	is_rectangle(map);
	ft_valid_wall_perimeter(map);
	cordo = ft_rows_cols_map(map);
	ft_nb_elmts(cordo.cols, cordo.rows, map);
	ft_elements_valid(cordo.cols, cordo.rows, map);
	player = ft_find_pos_player(map);
	ft_dfs(player.y, player.x, map, 'C');
	ft_find_elemt_dfs(cordo.cols, cordo.rows, map);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_pos		player;

	player = ft_find_pos_player(vars->map);
	if (keycode == 'w')
		ft_move_up(*vars, player, vars->map);
	if (keycode == 's')
		ft_move_down(*vars, player, vars->map);
	if (keycode == 'd')
		ft_move_right(*vars, player, vars->map);
	if (keycode == 'a')
		ft_move_left(*vars, player, vars->map);
	return (0);
}

int	main(void)
{
	char	*filename;
	char	**map;
	int		fd;
	int		size;
	t_sizemap cordo;
	t_vars		vars;
	int		nb_collect;

	filename = "map.ber";
	if (ft_endswith(filename) == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	size =  nb_line(fd);
	if (size == 0)
		return (0);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	map = tab_line(fd, size);
	cordo = ft_rows_cols_map(map);
	vars.map = ft_copy_array(map, cordo);
	ft_map_check(map);
	nb_collect = ft_nb_collect(cordo.cols, cordo.rows, vars.map);
	vars.count = &nb_collect;
	vars.wall = "./images/wall.xpm";
	vars.player = "./images/player.xpm";
	vars.back = "./images/back.xpm";
	vars.exit = "./images/exit.xpm";

/* ===> Minilibx <=== */ 
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1900, 1000, "So long");
	ft_display_sprite(cordo, vars, vars.map);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);
}

// TODO :
/*
=> tester la taille de chaque ligne

=> arreter le pgrogamme si il y a yn soucis
pour le moment il continue de 
checker les autres fonctions meme en cas d'erreur
avec celui du precendent
*/