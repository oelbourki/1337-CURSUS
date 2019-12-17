/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:52:42 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:52:43 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_the_info(t_cube *h, int fd)
{
	char	*line;
	int		i;

	i = 0;
	h->lx = 0;
	h->ly = 0;
	while (get_next_line(fd, &line) > 0)
	{
		h->old = g_size;
		g_size *= 2;
		h->map1 = ft_realloc(h->map1, h->old, g_size);
		if (h->map1 == NULL)
			error(11, h);
		if (get_info_help(h, line))
		{
			h->flag3 = 1;
			fill_line(h, line, &i);
		}
		if (h->flag3 == 1 && line[0] == '\0')
			error(205, h);
		free(line);
	}
	fill_line(h, line, &i);
	free(line);
	h->ly++;
}

int		check_row_1(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (i);
}

int		check_row_0(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == 'N' || s[i] == 'S' || s[i] == 'E'
		|| s[i] == 'W' || s[i] == '1' || s[i] == '0' || s[i] == '2'))
			return (-1);
		i++;
	}
	return (i);
}

int		check_all_map_error(t_cube *h)
{
	int t[h->ly];
	int	i;

	i = 1;
	t[0] = check_row_1(h->map1[0]);
	t[h->ly - 1] = check_row_1(h->map1[h->ly - 1]);
	if (t[0] != t[h->ly - 1])
		error(15, h);
	while (i < h->ly - 1)
	{
		t[i] = check_row_0(h->map1[i]);
		if (t[i - 1] != t[i] || h->map1[i][0] != '1'
		|| h->map1[i][h->lx - 1] != '1')
		{
			error(15, h);
			break ;
		}
		i++;
	}
	return (1);
}

int		get_the_cube(t_cube *h, int fd)
{
	get_the_info(h, fd);
	check_all_map_error(h);
	if (h->flag1 == 0)
		error(126, h);
	get_r(h);
	get_f(h);
	get_c(h);
	get_path_no(h);
	get_path_so(h);
	get_path_we(h);
	get_path_ea(h);
	get_path_ss(h);
	return (1);
}
