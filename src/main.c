/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:53:09 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 16:34:19 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int			close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int					main(int argc, char **argv)
{
	t_row			*list;
	t_together		*lst;
	unsigned int	test[1];
	int				fd;
	int				read_n;

	if (argc < 2)
		return (write(1, "usage: You hadn't send any argument.", 36));
	else if (argc > 2)
		return (write(1, "usage: You send too much arguments", 34));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || (read_n = read(fd, NULL, 0)) < 0
	|| (read(fd, test, 1)) <= 0)
		return (write(1, "usage: try to open another file\n", 32));
	close(fd);
	list = ft_read_map(&argv[1]);
	if (chack_map(list) == 1)
		return (write(1, "usage: try to open another file\n", 32));
	lst = give_tot_mem(list);
	mlx_hook(lst->win_ptr, 17, 0, close_window, 0);
	mlx_hook(lst->win_ptr, 2, 0, key_press, lst);
	mlx_loop(lst->mlx_ptr);
	return (0);
}
