/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:01:37 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 14:21:40 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		chack_symbol(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == '-' || (s[a] >= '0' && s[a] <= '9') || s[a] == ' ' ||
		s[a] == ',' || s[a] == 'x' || (s[a] >= 'A' && s[a] <= 'F') ||
		(s[a] >= 'a' && s[a] <= 'f'))
		{
			if (s[a] == '-' && (s[a + 1] < '0' || s[a + 1] > '9'))
				return (1);
			a++;
		}
		else
			return (1);
	}
	return (0);
}

int		chack_map(t_row *list)
{
	int	a;
	int	b;
	int	c;

	b = 0;
	c = 0;
	while (list)
	{
		a = 0;
		if (chack_symbol(list->row) == 1)
			return (1);
		while (list->row_el[a])
			a++;
		if (b == 0)
			b = a;
		if (a != b)
			return (1);
		list->el_num = a;
		list = list->next;
		c++;
	}
	return (0);
}
