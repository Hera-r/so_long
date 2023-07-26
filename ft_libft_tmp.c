/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:32:21 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/26 13:18:35 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

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
	int		tmp_cols;

	i = 0;
	tmp_cols = cordo.cols;
	copy_map = malloc((tmp_cols + 1) * sizeof(char *));
	if (copy_map == NULL)
		return (0);
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

int	ft_dif_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& s1[i] && s2[i] && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
