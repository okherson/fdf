/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:48:26 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 17:25:38 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	max(int a, int b)
{
	return (a < b ? b : a);
}

static int	absolut(int c)
{
	return (c < 0 ? -c : c);
}

static void	put_horiz(int c, t_together *lst, t_line l)
{
	l.d = -l.lengthx;
	l.length++;
	while (l.length--)
	{
		mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, l.x, l.y, c);
		l.x += l.dx;
		l.d += 2 * l.lengthy;
		if (l.d > 0)
		{
			l.d -= 2 * l.lengthx;
			l.y += l.dy;
		}
	}
}

static void	put_vert(int c, t_together *lst, t_line l)
{
	l.d = -l.lengthy;
	l.length++;
	while (l.length--)
	{
		mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, l.x, l.y, c);
		l.y += l.dy;
		l.d += 2 * l.lengthx;
		if (l.d > 0)
		{
			l.d -= 2 * l.lengthy;
			l.x += l.dx;
		}
	}
}

void		line(int *x, int *y, int c, t_together *lst)
{
	t_line	l;

	l.dx = (x[1] - x[0] >= 0 ? 1 : -1);
	l.dy = (y[1] - y[0] >= 0 ? 1 : -1);
	l.lengthx = absolut(x[1] - x[0]);
	l.lengthy = absolut(y[1] - y[0]);
	l.length = max(l.lengthx, l.lengthy);
	l.x = x[0];
	l.y = y[0];
	if (l.length == 0)
		mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, x[0], y[0], c);
	if (l.lengthy <= l.lengthx)
		put_horiz(c, lst, l);
	else
		put_vert(c, lst, l);
}
