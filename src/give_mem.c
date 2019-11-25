/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:59:27 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 17:13:00 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		put_c(char *s)
{
	int			a;
	int			b;

	a = 2;
	if (s != NULL && (s[0] == '0' && s[1] == 'x' && s[2] &&
	(b = strlen(s)) < 9))
	{
		while (a < b)
		{
			if ((s[a] >= '0' && s[a] <= '9') || (s[a] >= 'a' && s[a] <= 'f')
		|| (s[a] >= 'A' && s[a] <= 'F'))
				a++;
			else
				return (255255255);
		}
	}
	else
		return (255255255);
	return (convert_color(s));
}

static void		put_z(t_row *list, t_mas_map **map)
{
	int			x;
	int			y;
	char		**h_c;

	y = 0;
	while (y < map[0][0].map_size[0])
	{
		x = 0;
		while (x < map[0][0].map_size[1])
		{
			h_c = ft_strsplit(list->row_el[x], ',');
			map[y][x].fz = ft_atoi(h_c[0]);
			map[y][x].fcolor = put_c(h_c[1]);
			free(h_c[0]);
			if (h_c[1] != NULL)
				free(h_c[1]);
			free(h_c);
			x++;
		}
		y++;
		list = list->next;
	}
}

static void		free_list(t_row *list)
{
	int			a;

	while (list)
	{
		a = 0;
		free(list->row);
		while (list->row_el[a])
		{
			free(list->row_el[a]);
			a++;
		}
		free(list->row_el);
		free(list);
		list = list->next;
	}
}

t_mas_map		**give_mem(t_row *list)
{
	t_mas_map	**map;
	t_row		*l;
	int			a;
	int			b;

	l = list;
	while (list->next != NULL)
		list = list->next;
	a = 0;
	map = ft_memalloc(list->row_num * sizeof(t_mas_map *));
	while (a < list->row_num)
	{
		b = 0;
		map[a] = ft_memalloc(list->el_num * sizeof(t_mas_map));
		ft_bzero((void *)(map[a]), sizeof(t_mas_map));
		a++;
	}
	map[0][0].map_size[0] = list->row_num;
	map[0][0].map_size[1] = list->el_num;
	put_z(l, map);
	free_list(l);
	return (map);
}
