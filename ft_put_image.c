/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:23 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/20 02:19:45 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_images(t_vars vars, t_pos pos, char *img_path)
// {
// 	int		img_width;
// 	int		img_height;
// 	void	*img;

// 	img = mlx_xpm_file_to_image(vars.mlx, img_path, &img_width, &img_height);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img, pos.x * 43, pos.y * 50);

// }

void	ft_images(t_vars vars, t_pos player, char *img_path)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(vars.mlx, img_path, &img_width, &img_height);
	if (img != NULL)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img, player.x * 43, player.y * 50);
		free(img);
	}
}

// void	ft_display_sprite(t_sizemap cordo, t_vars vars, char **map)
// {
// 	t_pos 	pos;

// 	pos.y = 0;
// 	pos.x = 0;
// 	while (pos.y < cordo.cols)
// 	{
// 		while (pos.x < cordo.rows)
// 		{
// 			if (map[pos.y][pos.x] == '1')
// 				ft_images(vars, pos, "./images/wall.xpm");
// 			if (map[pos.y][pos.x] == 'C')
// 				ft_images(vars, pos, "./images/collectible.xpm");
// 			if (map[pos.y][pos.x] == 'E')
// 				ft_images(vars, pos, "./images/exit.xpm");
// 			if (map[pos.y][pos.x] == 'P')
// 				ft_images(vars, pos, "./images/player.xpm");
// 			if (map[pos.y][pos.x] == '0')
// 				ft_images(vars, pos, "./images/back.xpm");
// 		pos.x++;
// 		}
// 	pos.y++;
// 	pos.x = 0;
// 	}
// }

void	ft_display_sprite(t_sizemap cordo, t_vars vars, char **map)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < cordo.cols)
	{
		while (pos.x < cordo.rows)
		{
			if (map[pos.y][pos.x] == '1')
				ft_images(vars, pos, "./images/wall.xpm");
			else if (map[pos.y][pos.x] == 'C')
				ft_images(vars, pos, "./images/collectible.xpm");
			else if (map[pos.y][pos.x] == 'E')
			{
				// If there is a 'C' behind the 'E', show the 'C'
				if (map[pos.y][pos.x - 1] == 'C')
					ft_images(vars, pos, "./images/collectible.xpm");
				else
					ft_images(vars, pos, "./images/exit.xpm");
			}
			else if (map[pos.y][pos.x] == 'P')
				ft_images(vars, pos, "./images/player.xpm");
			else if (map[pos.y][pos.x] == '0')
				ft_images(vars, pos, "./images/back.xpm");
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
}