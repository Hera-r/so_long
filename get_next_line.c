/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:02:53 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/24 00:22:45 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\n')
			return (i);
	i++;
	}
	return (i);
}

static char	*get_remainder_str(char *str)
{
	char	*new_str;
	size_t	i;
	int		index;
	int		len_str;

	i = 0;
	len_str = ft_strlen(str);
	if (len_str == 0)
		return (str);
	index = ft_get_index(str);
	str = str + index;
	if (is_newline(str) == 0)
		str++;
	new_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (index >= len_str)
		return (new_str[0] = '\0', new_str);
	while (str[i])
	{
		new_str[i] = str[i];
	i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*join_and_str_remainder(char **result, char **buffer)
{
	char	*tmp;

	tmp = *result;
	*result = ft_strjoin(*result, *buffer);
	free(tmp);
	if (!*result)
		return (free(*buffer), NULL);
	tmp = *buffer;
	*buffer = get_remainder_str(*buffer);
	free(tmp);
	if (!*buffer)
		return (NULL);
	return (*result);
}

char	*first_and_next_gnl(char **buff_join, char **buffer, int n, int fd)
{
	if (!*buffer)
	{
		*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer)
			return (NULL);
		(*buffer)[0] = '\0';
	}
	if ((*buffer)[0] != '\0')
	{
		*buff_join = join_and_str_remainder(buff_join, buffer);
		if (!*buff_join)
			return (free(*buff_join), NULL);
	}
	else
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		if (n == -1 || n == 0)
			return (free(*buffer), *buffer = 0, NULL);
		(*buffer)[n] = '\0';
		*buff_join = join_and_str_remainder(buff_join, buffer);
		if (!*buff_join)
			return (free(*buff_join), NULL);
	}
	return (*buff_join);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*buff_join;
	int				n;

	buff_join = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	n = 1;
	buff_join = first_and_next_gnl(&buff_join, &buffer, n, fd);
	if (!buff_join)
		return (NULL);
	while (is_newline(buff_join) == 1)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == 0 || n == -1)
			return (free(buffer), buffer = 0, buff_join);
		buffer[n] = '\0';
		buff_join = join_and_str_remainder(&buff_join, &buffer);
		if (!buff_join)
			return (free(buff_join), NULL);
		if (!buffer)
			return (free(buff_join), NULL);
	}
	return (buff_join);
}