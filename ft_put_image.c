/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:23 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 22:38:46 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_all_img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->back = mlx_xpm_file_to_image(vars->mlx, \
	"./images/back.xpm", &img_width, &img_height);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx, \
	"./images/collectible.xpm", &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, \
	"./images/wall.xpm", &img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, \
	"./images/player.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, \
	"./images/exit.xpm", &img_width, &img_height);
	return (!vars->back || !vars->collectible || \
		!vars->wall || !vars->player || !vars->exit);
}

void	ft_images(t_vars vars, t_pos player, void *img)
{
	mlx_put_image_to_window(vars.mlx, vars.win, img, \
	player.x * 43, player.y * 50);
}

void	ft_destroy_img(t_vars *vars)
{
	if (vars->back)
		mlx_destroy_image(vars->mlx, vars->back);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->collectible)
		mlx_destroy_image(vars->mlx, vars->collectible);
	if (vars->exit)
		mlx_destroy_image(vars->mlx, vars->exit);
	if (vars->player)
		mlx_destroy_image(vars->mlx, vars->player);
}

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
				ft_images(vars, pos, vars.wall);
			else if (map[pos.y][pos.x] == 'C')
				ft_images(vars, pos, vars.collectible);
			else if (map[pos.y][pos.x] == 'E')
				ft_images(vars, pos, vars.exit);
			else if (map[pos.y][pos.x] == 'P')
				ft_images(vars, pos, vars.player);
			else if (map[pos.y][pos.x] == '0')
				ft_images(vars, pos, vars.back);
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
}
