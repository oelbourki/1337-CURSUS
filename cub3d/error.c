/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:47:54 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:47:56 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		free_split(char **h)
{
	int i;

	if (h == NULL)
		return (0);
	i = 0;
	while (h[i])
	{
		if (h[i])
			free(h[i]);
		h[i] = NULL;
		i++;
	}
	if (h)
		free(h);
	h = NULL;
	return (0);
}

void	ft_free(void *s)
{
	if (s)
		free(s);
	s = NULL;
}

int		red(t_cube *c)
{
	if (c->win_ptr && c->save == 0)
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	if (c->img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->img_ptr);
	if (c->file[0])
		mlx_destroy_image(c->mlx_ptr, c->file[0]);
	if (c->file[1])
		mlx_destroy_image(c->mlx_ptr, c->file[1]);
	if (c->file[2])
		mlx_destroy_image(c->mlx_ptr, c->file[2]);
	if (c->file[3])
		mlx_destroy_image(c->mlx_ptr, c->file[3]);
	if (c->file[4])
		mlx_destroy_image(c->mlx_ptr, c->file[4]);
	if (c->files)
		mlx_destroy_image(c->mlx_ptr, c->files);
	free_structure(c);
	exit(0);
}

void	free_structure(t_cube *h)
{
	ft_free(h->holder[0]);
	ft_free(h->holder[1]);
	ft_free(h->holder[2]);
	ft_free(h->holder[3]);
	ft_free(h->holder[4]);
	ft_free(h->holder[5]);
	ft_free(h->holder[6]);
	ft_free(h->holder[7]);
	ft_free(h->holder[8]);
	ft_free(h->no);
	ft_free(h->so);
	ft_free(h->we);
	ft_free(h->ea);
	ft_free(h->ss);
}
