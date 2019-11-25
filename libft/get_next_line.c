/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:55:13 by okherson          #+#    #+#             */
/*   Updated: 2019/03/29 10:45:46 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ffp(char *str, char **line)
{
	char		*fp;
	int			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	fp = (char *)malloc(i + 1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		fp[i] = str[i];
		i++;
	}
	fp[i] = '\0';
	*line = ft_strdup(fp);
	free(fp);
}

static int		line_write(char **mass, char **line)
{
	char		*dop2;

	if (*mass == NULL)
		return (0);
	if (ft_strchr(*mass, '\n') != NULL)
	{
		ffp(*mass, line);
		dop2 = *mass;
		*mass = ft_strdup(ft_strchr(*mass, '\n') + 1);
		free(dop2);
		return (1);
	}
	else if (ft_strchr(*mass, '\0') != NULL)
	{
		*line = ft_strdup(*mass);
		ft_memdel((void**)mass);
		if (*line[0] == '\0')
			return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[33];
	static char	*gnl[4096];
	char		*dop;
	int			n;

	if (fd < 0 || 32 < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	while ((n = read(fd, buff, 32)) > 0)
	{
		buff[n] = '\0';
		dop = gnl[fd];
		gnl[fd] = ft_strjoin(gnl[fd], buff);
		free(dop);
		if (ft_strchr(gnl[fd], '\n') != NULL)
			break ;
	}
	if (gnl[fd] == NULL)
		return (0);
	if (line_write(&gnl[fd], line) == 1)
		return (1);
	return (0);
}
