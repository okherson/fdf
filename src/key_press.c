/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:53:54 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 15:30:54 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	round_map(int key, t_together *lst)
{
	if (key == 1)
		lst->a[0] = lst->a[0] - 0.174533;
	if (key == 13)
		lst->a[0] = lst->a[0] + 0.174533;
	if (key == 2)
		lst->a[1] = lst->a[1] + 0.174533;
	if (key == 0)
		lst->a[1] = lst->a[1] - 0.174533;
	if (key == 12)
		lst->a[2] = lst->a[2] - 0.174533;
	if (key == 14)
		lst->a[2] = lst->a[2] + 0.174533;
	iso(lst);
}

static void	move(int key, t_together *lst)
{
	if (key == 123 && lst->pos[1] >= lst->tyx[1] + 5)
		lst->pos[1] = lst->pos[1] - 20;
	if (key == 124 && lst->pos[1] <= 1585)
		lst->pos[1] = lst->pos[1] + 20;
	if (key == 125 && lst->pos[0] <= 1190)
		lst->pos[0] = lst->pos[0] + 20;
	if (key == 126 && lst->pos[0] >= 20)
		lst->pos[0] = lst->pos[0] - 20;
	if (key == 31 && lst->zoom >= 3)
		lst->zoom = lst->zoom - 2;
	if (key == 35 && lst->zoom <= 50)
		lst->zoom = lst->zoom + 2;
	if (key == 6 && lst->hz <= 25)
		lst->hz = lst->hz + 1;
	if (key == 7 && lst->hz >= -25)
		lst->hz = lst->hz - 1;
	iso(lst);
}

static void	ft_color(int key, t_together *lst)
{
	int		x;
	int		y;
	int		c;

	y = 0;
	while (y < lst->tyx[0])
	{
		x = 0;
		while (x < lst->tyx[1])
		{
			if (key == 8 && lst->m[y][x].chcolor <= 255255255)
				c = 500050;
			else if (key == 9 && lst->m[y][x].chcolor >= 50050050)
				c = -500050;
			else
				c = 0;
			lst->m[y][x].chcolor += c;
			x++;
		}
		y++;
	}
	iso(lst);
}

static void	proection(int k, t_together *lst)
{
	if (k == 19)
	{
		mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
		lst->a[0] = 0.523599;
		lst->a[1] = 0.523599;
		lst->a[2] = 0.523599;
		lst->hz = 2;
		iso(lst);
	}
	else if (k == 20)
	{
		mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
		lst->a[0] = 0;
		lst->a[0] = 1.5708;
		lst->a[1] = 0;
		lst->hz = 2;
		iso(lst);
	}
}

int			key_press(int k, t_together *lst)
{
	if (k == 53)
		exit(0);
	else if (k == 123 || k == 124 || k == 125 || k == 126 || k == 31 || k == 35
	|| k == 6 || k == 7)
		move(k, lst);
	else if (k == 0 || k == 1 || k == 2 || k == 13 || k == 12 || k == 14)
		round_map(k, lst);
	else if (k == 18)
	{
		mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
		lst->a[0] = 0;
		lst->a[1] = 0;
		lst->a[2] = 0;
		lst->hz = 2;
		iso(lst);
	}
	else if (k == 19 || k == 20)
		proection(k, lst);
	else if (k == 8 || k == 9)
		ft_color(k, lst);
	return (0);
}
