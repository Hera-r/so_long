/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/14 22:04:06 by hrandria         ###   ########.fr       */
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



int	main(void)
{
	char	*filename;
	char	**map;
	char	**copy_map;
	int		fd;
	int		size;
	// void	*mlx;
	// void	*mlx_win;
	t_sizemap cordo;
	t_vars		vars;

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

	copy_map = ft_copy_array(map, cordo);
	ft_map_check(map);

/* ===> Minilibx <=== */ 
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1900, 1000, "So long");

	ft_display_sprite(cordo, vars, copy_map);
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