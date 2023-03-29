/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:42:14 by hrandria          #+#    #+#             */
/*   Updated: 2023/03/27 18:10:33 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(int count, char *buffer)
{
	int	i;
	int	tmp;
	int	f_line;

	// f_line = 13; // toDo: boucle la première line
	i = 0;
	while (buffer[i] != '\n')
	i++;
	f_line = i;
	i = 0;
	while (count)
	{
		tmp = i;
		while (buffer[i] && buffer[i] != '\n')
		i++;
	if (f_line != (i - tmp))
	{
	printf("NOT RECtangle");
	return (1);
	}
	count--;
	i += 1;
	}
	printf("ok ok");
	return (0);
}