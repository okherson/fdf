/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:34:00 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 15:18:06 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		put_angle_m(t_together *lst)
{
	double	x;
	double	y;
	double	z;

	x = lst->a[0];
	y = lst->a[1];
	z = lst->a[2];
	lst->angle_m[0][0] = 0.5 * (cos(y + z) + cos(y - z));
	lst->angle_m[0][1] = 0.5 * (-sin(y + z) + sin(y - z));
	lst->angle_m[0][2] = sin(y);
	lst->angle_m[1][0] = 0.25 * (-cos(x + y + z) + cos(x - y + z) -
	cos(x + y - z) + cos(x - y - z) + 2 * sin(x + z) - 2 * sin(x - z));
	lst->angle_m[1][1] = 0.25 * (2 * cos(x + z) + 2 * cos(x - z) +
	sin(x + y + z) - sin(x - y + z) - sin(x + y - z) + sin(x - y - z));
	lst->angle_m[1][2] = 0.5 * (-sin(x + y) - sin(x - y));
	lst->angle_m[2][0] = 0.25 * (-2 * cos(x + z) + 2 * cos(x - z) -
	sin(x + y + z) + sin(x - y + z) - sin(x + y - z) + sin(x - y - z));
	lst->angle_m[2][1] = 0.25 * (-cos(x + y + z) + cos(x - y + z) +
	cos(x + y - z) - cos(x - y - z) + 2 * sin(x + z) + 2 * sin(x - z));
	lst->angle_m[2][2] = 0.5 * (cos(x + y) + cos(x - y));
}

static void	put_xyz(int *xyz, t_mas_map *m, t_together *lst)
{
	m->chx = round(xyz[0] * lst->angle_m[0][0] + xyz[1] * lst->angle_m[0][1] +
	xyz[2] * lst->angle_m[0][2]);
	m->chy = round(xyz[0] * lst->angle_m[1][0] + xyz[1] * lst->angle_m[1][1] +
	xyz[2] * lst->angle_m[1][2]);
	m->chz = round(xyz[0] * lst->angle_m[2][0] + xyz[1] * lst->angle_m[2][1] +
	xyz[2] * lst->angle_m[2][2]);
}

void		iso(t_together *lst)
{
	int		a;
	int		b;
	int		xyz[3];

	a = 0;
	put_angle_m(lst);
	while (a < lst->tyx[0])
	{
		b = 0;
		while (b < lst->tyx[1])
		{
			xyz[0] = lst->m[a][b].fx * lst->zoom;
			xyz[1] = lst->m[a][b].fy * lst->zoom;
			xyz[2] = lst->m[a][b].fz * lst->hz;
			put_xyz(xyz, &lst->m[a][b], lst);
			b++;
		}
		a++;
	}
	mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
	paint_iso(lst);
}
