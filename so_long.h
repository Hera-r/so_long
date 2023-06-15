/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:03:35 by hrandria          #+#    #+#             */
/*   Updated: 2023/06/15 18:13:28 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**tab_line(int fd, int size);
int		is_newline(char *str_line);
int     ft_len_not_newline(char *str);
int     count_element_tab(char **tab);
int	    ft_endswith(char *filename);
int		ft_strlen(char *str);
int     nb_line(int fd);
int	    is_rectangle(char **tab);
int     ft_valid_wall_perimeter(char **tab);

typedef struct t_point{
	int	x;
	int	y;
}			t_pos;
typedef struct t_cordo{
	int	rows;
	int	cols;
}			t_sizemap;
typedef struct t_axe{
    int *dx;
    int *dy;
}			t_axe;
typedef struct t_elements{
	int	c;
	int	e;
	int	p;
}			t_elements;
t_axe		ft_init_axe(void);
t_sizemap	ft_rows_cols_map(char **map);
t_pos		ft_find_pos_player(char **map);
int			ft_dfs(int x, int y, char **map, char target);
int			ft_find_elemt_dfs(int cols, int rows, char **map);
int			ft_elements_valid(int cols, int rows, char **map);
int			ft_nb_elmts(int cols, int rows, char **map);
#endif
