/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:45:42 by hrandria          #+#    #+#             */
/*   Updated: 2023/03/27 18:07:32 by hrandria         ###   ########.fr       */
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
	char	buffer[100];
	int		fd;
	int		i;
	int		count;
	ssize_t	nread;

	count = 0;
	i = 0;
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
		{
			printf("in while -> %d\n", count);
			count += 1;
		}
	i++;
	}
	
	if (buffer[i] == '\0')
		count -= 1;
	count += 1;
	printf("Total -> %d\n", count);
	
	is_rectangle(count, buffer);
	if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
	return (0);
}
