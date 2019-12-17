/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:26 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:04:29 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_path_no(t_cube *h)
{
	char **h1;

	if (h->no != NULL)
		error(94, h);
	if (!h->holder[1])
		error(16, h);
	if (!(h1 = ft_split(h->holder[2], ' ')))
		error(9, h);
	if (h1[0][2] != '\0')
		free_error(h1, 120, h);
	if (h1[2] != NULL)
		error(85, h);
	if (!(h->no = ft_strdup(h1[1])))
	{
		free_split(h1);
		error(10, h);
	}
	free_split(h1);
	return (1);
}

int		get_path_so(t_cube *h)
{
	char **h1;

	if (h->so != NULL)
		error(93, h);
	if (!h->holder[2])
		error(16, h);
	if (!(h1 = ft_split(h->holder[2], ' ')))
		error(9, h);
	if (h1[0][2] != '\0')
		free_error(h1, 120, h);
	if (h1[2] != NULL)
		error(85, h);
	if (!(h->so = ft_strdup(h1[1])))
	{
		free_split(h1);
		error(10, h);
	}
	free_split(h1);
	return (1);
}

int		get_path_we(t_cube *h)
{
	char **h1;

	if (h->we != NULL)
		error(92, h);
	if (!h->holder[3])
		error(16, h);
	if (!(h1 = ft_split(h->holder[3], ' ')))
		error(9, h);
	if (h1[0][2] != '\0')
		free_error(h1, 120, h);
	if (h1[2] != NULL)
		error(85, h);
	if (!(h->we = ft_strdup(h1[1])))
	{
		free_split(h1);
		error(10, h);
	}
	free_split(h1);
	return (1);
}

int		get_path_ea(t_cube *h)
{
	char **h1;

	if (h->ea != NULL)
		error(91, h);
	if (!h->holder[4])
		error(16, h);
	if (!(h1 = ft_split(h->holder[4], ' ')))
		error(9, h);
	if (h1[0][2] != '\0')
		free_error(h1, 120, h);
	if (h1[2] != NULL)
		error(85, h);
	if (!(h->ea = ft_strdup(h1[1])))
	{
		free_split(h1);
		error(10, h);
	}
	free_split(h1);
	return (1);
}

int		get_path_ss(t_cube *h)
{
	char **h1;

	if (h->ss != NULL)
		error(90, h);
	if (!h->holder[5])
		error(16, h);
	if (!(h1 = ft_split(h->holder[5], ' ')))
		error(9, h);
	if (h1[0][1] != '\0')
		free_error(h1, 120, h);
	if (h1[2] != NULL)
		error(85, h);
	if (!(h->ss = ft_strdup(h1[1])))
	{
		free_split(h1);
		error(10, h);
	}
	free_split(h1);
	return (1);
}
