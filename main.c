/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/25 20:48:08 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_check(char **map)
{
	t_pos		player;
	t_sizemap	cordo;

	cordo = ft_rows_cols_map(map);
	if (ft_max_len_map(cordo) == 1)
		return (FAIL);
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

int	main(int argc, char *argv[])
{
	int			fd2;
	char		**map;
	char		**map_cpy;
	t_sizemap	cordo;
	int			size;

	size = 0;
	if (argc == 2)
	{
		size = ft_size_line(argv[1]);
		if (size == 1)
			return (0);
		fd2 = ft_second_fd(argv[1]);
		map = tab_line(fd2, size);
		close(fd2);
		cordo = ft_rows_cols_map(map);
		map_cpy = ft_copy_array(map, cordo);
		if (ft_map_check(map) == FAIL)
			return (ft_free_map(map), ft_free_map(map_cpy), FAIL);
		ft_free_map(map);
		if (ft_the_game(map_cpy) == 1)
			return (FAIL);
		ft_free_map(map_cpy);
	}
}
