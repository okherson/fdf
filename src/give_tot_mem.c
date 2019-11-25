/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_tot_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:00:50 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 16:34:15 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		put_xy(t_together *lst)
{
	int			x;
	int			y;

	y = 0;
	while (y < lst->tyx[0])
	{
		x = 0;
		while (x < lst->tyx[1])
		{
			lst->m[y][x].fx = x;
			lst->m[y][x].chx = x;
			lst->m[y][x].fy = y;
			lst->m[y][x].chy = y;
			lst->m[y][x].chz = lst->m[y][x].fz;
			lst->m[y][x].chcolor = lst->m[y][x].fcolor;
			x++;
		}
		y++;
	}
}

t_together		*give_tot_mem(t_row *list)
{
	t_together	*lst;

	lst = malloc(sizeof(t_together));
	lst->m = give_mem(list);
	lst->tyx[0] = lst->m[0][0].map_size[0];
	lst->tyx[1] = lst->m[0][0].map_size[1];
	lst->zoom = 3;
	lst->win_size[0] = 1200;
	lst->win_size[1] = 1600;
	lst->pos[0] = (lst->win_size[0] - lst->tyx[0] * lst->zoom) / 2;
	lst->pos[1] = (lst->win_size[1] - lst->tyx[1] * lst->zoom) / 2;
	lst->a[0] = 0;
	lst->a[1] = 0;
	lst->a[2] = 0;
	lst->hz = 2;
	lst->mlx_ptr = mlx_init();
	lst->win_ptr = mlx_new_window(lst->mlx_ptr, 1600, 1200, "fdf");
	put_xy(lst);
	paint_iso(lst);
	return (lst);
}
