/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/03/27 17:39:39 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);

// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"


int	is_rectangle(int count, char *buffer)
{
	int	i;
	int	tmp;
	int	f_line;

	f_line = 13;
	i = 0;
	while (count)
	{
		tmp = i;
		while (buffer[i] && buffer[i] != '\n')
		i++;
	if (f_line != (i - tmp))
	{
		printf("error rectagnle\n");
		return (1);
	}
	count--;
	i += 1;
	}
	printf("Ok rectangle");
	return (0);
}



int	main(void)
{
	char	buffer[100];
	int		fd;
	int		i;
	int		count;
	ssize_t	nread;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	nread = read(fd, buffer, sizeof(buffer));

	if (nread == - 1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count += 1;
	i++;
	}
	if (buffer[i] == '\0')
		count -= 1;

	is_rectangle(count, buffer);

	if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
	return (0);
}
