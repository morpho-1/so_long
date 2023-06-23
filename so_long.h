/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:13:24 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/23 03:24:09 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

# define C "xpm/coin.xpm"
# define PL "xpm/player.xpm"
# define D "xpm/door.xpm"
# define W "xpm/wall.xpm"
# define B "xpm/blank.xpm"

typedef enum e_event
{
	UP = 126,
	DW = 125,
	LF = 123,
	RT = 124,
	ESC = 53,
}	t_event;

typedef struct s_img
{
	void	*player;
	void	*coin;
	void	*door;
	void	*wall;
	void	*road;
}	t_img;

typedef struct s_vars
{
	t_img	img;
	int		py;
	int		px;
	int		m_h;
	int		m_w;
	int		coins;
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapcopy;
}	t_vars;

int		is_token(char c);
int		close_window(t_vars *vars);
int		valid_extention(char *file);
int		ft_match(char c, char *s);
int		pos_filled(char **map, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_walls(t_vars *vars);
int		check_character(t_vars *vars, int x, int y);
int		ft_check_e(t_vars *vars, int x, int y);
int		move_player(int key, t_vars *vars);
void	free_map(char **map);
void	ft_move(t_vars *vars, int row, int col);
void	init_images(t_vars *vars);
void	ft_putstr_fd(char *s, int fd);
void	ft_put_image(t_vars *vars, int x, int y);
void	*ft_memset(void *str, int c, size_t n);
void	check_exit(t_vars *vars, int x, int y);
void	check_map(t_vars *vars);
void	check_path(t_vars *vars);
void	ft_perror(char *err);
void	parse_map(t_vars *vars, char *file);
void	render_map(t_vars *vars);
void	render_game(t_vars *vars);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	**copy_map(char **map, int len);

#endif
