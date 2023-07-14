/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:19:28 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/15 01:21:29 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_pos player, t_pos pos, char **map)
{
	int	img_width; 
	int	img_height;

	pos.y = player.y + 1;
	if (map[pos.y][pos.x] != '1')
		ft_images(vars, pos, "./images/player.xpm")
}