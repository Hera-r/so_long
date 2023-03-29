/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/03/29 23:52:52 by hrandria         ###   ########.fr       */
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
	int		i;
	char	**tab;
	char	*filename;
	int		size;

	i = 0;
	filename = "map.ber";
	if (ft_endswith(filename) == 1)
		return (0);
	fd = open("map.ber", O_RDONLY);
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
	while (tab[i])
	{
		printf("%s", tab[i]);
	i++;
	}
	return (0);
}

// TODO :
// tester la taille de chaque ligne