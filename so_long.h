/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:03:35 by hrandria          #+#    #+#             */
/*   Updated: 2023/07/25 20:46:53 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SUCCESS 0
# define FAIL 1
# define XK_ESCAPE 0xff1b

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
# include "ft_printf/ft_printf.h"

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		**tab_line(int fd, int size);
int			is_newline(char *str_line);
int			ft_len_not_newline(char *str);
int			count_element_tab(char **tab);
int			ft_endswith(char *filename);
int			ft_strlen(char *str);
int			nb_line(int fd);
int			is_rectangle(char **tab);
int			ft_valid_wall_perimeter(char **tab);

typedef struct t_point{
	int	x;
	int	y;
}			t_pos;
typedef struct t_cordo{
	int	rows;
	int	cols;
}			t_sizemap;
typedef struct t_axe{
	int	*dx;
	int	*dy;
}				t_axe;
typedef struct t_elements{
	int	c;
	int	e;
	int	p;
}			t_elements;
typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		*count;
	void	*wall;
	void	*exit;
	void	*player;
	void	*back;
	void	*collectible;
	int		*nb_move;
}				t_vars;
t_axe		ft_init_axe(void);
t_sizemap	ft_rows_cols_map(char **map);
t_pos		ft_find_pos_player(char **map);
int			ft_dfs(int y, int x, char **map);
int			ft_find_elemt_dfs(int cols, int rows, char **map);
int			ft_elements_valid(int cols, int rows, char **map);
int			ft_nb_elmts(int cols, int rows, char **map);
void		ft_display_sprite(t_sizemap cordo, t_vars vars, char **map);
char		*ft_strdup(char *s);
char		**ft_copy_array(char **map, t_sizemap cordo);
void		ft_images(t_vars vars, t_pos player, void *img);
void		ft_move_up(t_vars vars, t_pos player, char **map);
void		ft_move_down(t_vars vars, t_pos player, char **map);
void		ft_move_right(t_vars vars, t_pos player, char **map);
void		ft_move_left(t_vars vars, t_pos player, char **map);

void		ft_free_map(char **map);
int			ft_nb_collect(int cols, int rows, char **map);
int			exit_hook(t_vars *vars);
int			ft_dif_wall(char *str);
int			ft_size_line(char *filename);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_all_img(t_vars *vars);
int			ft_second_fd(char *filename);
void		ft_destroy_img(t_vars *vars);
int			ft_the_game(char **map_cpy);
int			ft_max_len_map(t_sizemap cordo);
#endif
