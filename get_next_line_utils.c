/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:03:16 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/22 00:17:03 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_newline(char *str_line)
{
	int	i;

	i = 0;
	if (!str_line)
		return (0);
	while (str_line[i])
	{
		if (str_line[i] == '\n')
			return (0);
	i++;
	}
	return (1);
}

static int	ft_compute(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	int			len_str;
	char		*new_str;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	len_str = ft_compute(s2);
	if (s1)
		len_str += ft_strlen(s1);
	new_str = malloc((len_str + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
	i++;
	}
	while (s2[j] && s2[j] != '\n')
		new_str[i++] = s2[j++];
	if (s2[j] && s2[j] == '\n')
		new_str[i++] = '\n';
	return (new_str[i] = '\0', new_str);
}
