/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:02:37 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:04:24 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mllx
{
	void	*mlx;
	void	*win;
}			t_mllx;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_vars
{
	t_point	*size;
	char	**map;
	void	*img;
	void	*wall;
	void	*vide;
	void	*play;
	void	*coin;
	void	*exit;
	t_point	*pose;
	int		img_width;
	int		img_height;
	t_mllx	*mllx;
	int		nb;

}			t_vars;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef SIZE_MAX
#  define SIZE_MAX 1024
# endif

///////// GET NEXT LIFE /////////
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			if_bn(char *str);
char		*ft_free(char *str);

///////// PARSING /////////
int			line_analyse(char **str);
int			check_form(char **str);
int			ft_parsing(char *av);
char		*lire(char *av);
char		**lire2(char *av);
char		**to_split(char *str);
int			periphe(char **str);
t_point		*started(char **str, t_point *pose);
int			flood_fill(char **tab, t_point *size, int x, int y);
char		**f_fill(char **map, t_point size, int row, int col);
t_point		*size_map(char **map, t_point *size);
void		ft_frip(char **map, t_point *pose, t_point *size);
void		ft_frip2(char **map, t_point *pose, t_point *size);
void		ft_frip3(char *str, t_point *pose, t_point *size);
int			check_ber(char *str);
int			anafull(char *str, char **map, t_point *pose, t_point *size);
int			pec(char **str, int p, int e, int c);
int			check_twoligne(char *av);
void		ft_null(t_vars *all);

///////// WINDOW /////////
char		*img_case(char c);
int			if_c(char **map);
void		render(t_vars *all);
int			check_finish(int keycode, t_vars *all);
int			finish(char **map);
int			end_game(t_vars *all);
int			imp_image_to_window(t_vars *all);
void		render_util(t_vars *all, char c, int y, int x);
int			show_wind(t_vars *all);

///////// MOVE /////////
int			walk(int keycode, t_vars *all);
char		*walk2(int keycode, t_vars *all);
void		can_walk(int keycode, t_vars *all);
void		anime(t_vars *all, char **map);
int			affnb(t_vars *all);
void		moveplus(t_vars *all);
void		movekey(int key, t_vars *all);

///////// LIBFT /////////
char		**ft_split(char *s, char c);
int			ft_strlen(char *s);
int			ft_varclear(t_vars *all);
int			ft_pointclear(t_point *point);
void		free_ptr(void **ptr);
void		ft_putnbr(int n);
char		*ft_itoa(int nb);

#endif
