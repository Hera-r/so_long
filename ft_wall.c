/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:34:16 by hrandria          #+#    #+#             */
/*   Updated: 2023/04/03 17:08:37 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_not_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	i++;
	return (i);
}

int	count_element_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	i++;
	return (i);
}

int	is_rectangle(char **tab)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = ft_len_not_newline(tab[0]);
	while (tab[i])
	{
		if (tmp != ft_len_not_newline(tab[i]))
		{
			printf("Not rectangle\n");
			return (1);
		}
	i++;
	}
	return  (0);
}

int	ft_valid_wall_perimeter(char **tab)
{
	int	tab_size;
	int	len_str;
	int	i;

	i = 0;
	tab_size = count_element_tab(tab) - 1;
	while (tab[0][i] && tab[0][i] != '\n')
	{
		if (tab[0][i] != '1')
		{
			printf("not valid top\n");
			return (1);
		}
		if (tab[tab_size][i] != '1')
		{
			printf("not valid bottom\n");
			return (1);
		}
	i++;
	}
	i = 1;
	len_str = ft_len_not_newline(tab[0]) - 1;
	while (i < tab_size)
	{
		if (tab[i][0] != '1' ||  tab[i][len_str] != '1')
		{
			printf("not valid start or end the line\n");
			return (1);
		}
	i++;
	}
	return (0);
}