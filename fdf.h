/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:42 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 17:24:31 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_mas_map
{
	int				map_size[2];
	int				fx;
	int				fy;
	int				fz;
	int				fcolor;
	int				chy;
	int				chx;
	int				chz;
	int				chcolor;
}					t_mas_map;

typedef struct		s_together
{
	t_mas_map		**m;
	double			angle_m[3][3];
	int				tyx[2];
	int				zoom;
	int				win_size[2];
	int				pos[2];
	double			a[3];
	int				hz;
	void			*win_ptr;
	void			*mlx_ptr;
}					t_together;

typedef struct		s_row
{
	char			*row;
	int				row_num;
	char			**row_el;
	int				el_num;
	struct s_row	*next;
}					t_row;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				lengthx;
	int				lengthy;
	int				length;
	int				x;
	int				y;
	int				d;
}					t_line;

t_row				*ft_read_map(char **argv);
int					chack_map(t_row *list);
t_mas_map			**give_mem(t_row *list);
int					convert_color(char *str);
t_together			*give_tot_mem(t_row *list);
void				paint_1p(t_together *lst);
int					key_press(int key, t_together *lst);
void				iso(t_together *lst);
void				paint_iso(t_together *lst);
void				line(int *x, int *y, int c, t_together *lst);

#endif
