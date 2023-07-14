/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:32:21 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/14 19:53:12 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*new_space;
	size_t	len_str;
	int		i;

	len_str = ft_strlen(s) + 1;
	new_space = malloc(len_str * sizeof(char));
	i = 0;
	if (new_space == NULL)
		return (NULL);
	while (s[i])
	{
		new_space[i] = s[i];
	i++;
	}
	new_space[i] = '\0';
	return (new_space);
}

char	**ft_copy_array(char **map, t_sizemap cordo)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(cordo.cols  * sizeof(char *));
	if (copy_map == NULL)
		return (0);
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
	i++;
	}
	return (copy_map);
}