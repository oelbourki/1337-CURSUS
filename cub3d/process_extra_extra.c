/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_extra_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:46 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:04:48 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_error(char **s, int e, t_cube *h)
{
	free_split(s);
	error(e, h);
}

void	free_error1(char **s, char **s1, int e, t_cube *h)
{
	free_split(s);
	free_split(s1);
	error(e, h);
}

int		get_r(t_cube *h)
{
	char **s;

	if (!h->holder[0])
		error(16, h);
	if (!(s = ft_split(h->holder[0], ' ')))
		error(9, h);
	if (s[0][1] != '\0')
		free_error(s, 120, h);
	if (s[1] == NULL || s[2] == NULL)
		error(98, h);
	if (s[3] != NULL)
		error(85, h);
	h->width = ft_atoi(s[1]);
	h->height = ft_atoi(s[2]);
	free_split(s);
	if (h->width < 0 || h->height < 0)
		error(105, h);
	h->width = (h->width > 2560 ? 2560 : h->width);
	h->height = (h->height > 1440 ? 1440 : h->height);
	return (1);
}

void	get_f(t_cube *h)
{
	char *s;

	if (!h->holder[6])
		error(16, h);
	if (!checklinex(h->holder[6], "0123456789, F"))
		error(120, h);
	if (!(s = give(h->holder[6])))
		error(96, h);
	h->r = ft_atoi(s);
	if (!(s = ft_strchr(s, ',')) || !(s[1] >= '0' && s[1] <= '9'))
		error(96, h);
	h->g = ft_atoi(s + 1);
	if (!(s = ft_strchr(s + 1, ',')) || !(s[1] >= '0' && s[1] <= '9'))
		error(96, h);
	h->b = ft_atoi(s + 1);
	if (h->r < 0 || h->g < 0 || h->b < 0 ||
	h->r > 255 || h->g > 255 || h->b > 255)
		error(119, h);
	h->f = h->r * 16 * 16 * 16 * 16 + h->g * 16 * 16 + h->b;
}

void	get_c(t_cube *h)
{
	char *s;

	if (!h->holder[7])
		error(16, h);
	if (!checklinex(h->holder[7], "0123456789, C"))
		error(120, h);
	if (!(s = give(h->holder[7])))
		error(97, h);
	h->r = ft_atoi(s);
	if (!(s = ft_strchr(s, ',')) || !(s[1] >= '0' && s[1] <= '9'))
		error(97, h);
	h->g = ft_atoi(s + 1);
	if (!(s = ft_strchr(s + 1, ',')) || !(s[1] >= '0' && s[1] <= '9'))
		error(97, h);
	h->b = ft_atoi(s + 1);
	if (h->r < 0 || h->g < 0 || h->b < 0 ||
	h->r > 255 || h->g > 255 || h->b > 255)
		error(119, h);
	h->c = h->r * 16 * 16 * 16 * 16 + h->g * 16 * 16 + h->b;
}
