/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/06/01 15:40:40 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		fd;
	// int		i;
	char	**tab;
	char	*filename;
	int		size;
	int		count;
	// int		y;
	// int		x;

	// y = 0;
	// x = 0;
	// t_sizemap cordo;
	t_pos	player;

	// i = 0;
	count = 0;
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
	tab = tab_line(fd, size);
	is_rectangle(tab);
	ft_valid_wall_perimeter(tab);
	// cordo = ft_rows_cols_map(tab);
	player = ft_find_pos_player(tab);

	// while (y < cordo.cols)
	// {
	// 	while (x < cordo.rows)
	// 	{
			// if (tab[y][x] == 'C')
			// {
				// printf(" position C est: (%d ,%d)\n", y, x);
				if (ft_dfs(player.y, player.x, tab, 'C') == 0)
				{
					count++;
					printf("Le nombre de C est (%d).\n", count);
				}
			// }
	// 	x++;
	// 	}
	// y++;
	// x = 0;
	// }
	return (0);
}

// TODO :
// tester la taille de chaque ligne