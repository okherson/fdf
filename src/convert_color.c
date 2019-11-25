/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 08:03:32 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 14:26:13 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			convert_color(char *str)
{
	int		a;
	int		b;
	int		c;
	int		num;
	char	**color_write;

	color_write = ft_strsplit(str, 'x');
	a = 5;
	b = 0;
	num = 0;
	while (a >= 0)
	{
		if (color_write[1][b] >= '0' && color_write[1][b] <= '9')
			c = color_write[1][b] - '0';
		else if (color_write[1][b] >= 'A' && color_write[1][b] <= 'F')
			c = color_write[1][b] - 55;
		num = num + c * pow(16, a);
		a--;
		b++;
	}
	free(color_write[0]);
	if (color_write[1] != NULL)
		free(color_write[1]);
	free(color_write);
	return (num);
}
