/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/06/15 17:58:18 by hrandria         ###   ########.fr       */
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


// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);

// 	return (0);
// }


int	main(void)
{
	char	*filename;
	char	**map;
	char	**copy_map;
	int		fd;
	int		size;

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
	copy_map = map;
	ft_map_check(map);

/* ===> Minilibx <=== */ 

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);


	return (0);
}



// TODO :
/*
=> tester la taille de chaque ligne

=> arreter le pgrogamme si il y a yn soucis
pour le moment il continue
de checker les autres fonctions meme en cas d'erreur
avec celui du precend
*/