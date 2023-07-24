/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_dfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:05:03 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 22:38:55 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_tab_axe(int a, int b, int c, int d)
{
	int	*axe_x;

	axe_x = (int *)malloc(4 * sizeof(int));
	if (!axe_x)
		return (0);
	axe_x[0] = a;
	axe_x[1] = b;
	axe_x[2] = c;
	axe_x[3] = d;
	return (axe_x);
}

t_axe	ft_init_axe(void)
{
	t_axe	axes;

	axes.dx = ft_tab_axe(0, 1, 0, -1);
	axes.dy = ft_tab_axe(-1, 0, 1, 0);
	return (axes);
}

int	ft_size_line(char *filename)
{
	int	size;
	int	fd;

	size = 0;
	if (ft_endswith(filename) == 1)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (FAIL);
	}
	size = nb_line(fd);
	if (size == 1)
	{
		ft_printf("Error\nmap.ber empty or not valid \n");
		return (close(fd), 1);
	}
	return (close(fd), size);
}
