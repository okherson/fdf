/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:15:17 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 16:15:31 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	send(t_mas_map *a, t_mas_map *b, t_together *lst)
{
	int		x[2];
	int		y[2];
	int		c;

	c = (a->chcolor);
	x[0] = a->chx + lst->pos[1];
	x[1] = b->chx + lst->pos[1];
	y[0] = a->chy + lst->pos[0];
	y[1] = b->chy + lst->pos[0];
	line(x, y, c, lst);
}

void		paint_iso(t_together *lst)
{
	int		y;
	int		x;

	y = 0;
	while (y < lst->tyx[0])
	{
		x = 0;
		while (x < lst->tyx[1])
		{
			if (lst->tyx[1] == 1 && lst->tyx[0] == 1)
				mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, lst->m[0][0].chx +
			lst->pos[1], lst->m[0][0].chy + lst->pos[0], lst->m[0][0].chcolor);
			if (x == lst->tyx[1] - 1 && y == lst->tyx[0] - 1)
				break ;
			if (x != lst->tyx[1] - 1)
				send(&(lst->m[y][x]), &(lst->m[y][x + 1]), lst);
			if (y != lst->tyx[0] - 1)
				send(&(lst->m[y][x]), &(lst->m[y + 1][x]), lst);
			x++;
		}
		y++;
	}
}
