/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:01:42 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:01:45 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	drawimg(t_cube *c)
{
	int j;
	int d;

	j = -1;
	while (++j < c->ds)
		c->s[j * c->width + c->x] = c->c;
	while (j < c->drawend)
	{
		d = j * 256 - c->height * 128 + c->lh * 128;
		c->texy = ((d * c->texh) / c->lh) / 256;
		if (c->side == 0 && c->rdx > 0)
			c->s[j * c->width + c->x] = c->xpm[0][c->texy * 64 + c->texx];
		if (c->side == 0 && c->rdx <= 0)
			c->s[j * c->width + c->x] = c->xpm[1][c->texy * 64 + c->texx];
		else if (c->side == 1 && c->rdy <= 0)
			c->s[j * c->width + c->x] = c->xpm[2][c->texy * 64 + c->texx];
		else if (c->side == 1 && c->rdy > 0)
			c->s[j * c->width + c->x] = c->xpm[3][c->texy * 64 + c->texx];
		j++;
	}
	while (j < c->height)
	{
		c->s[j * c->width + c->x] = c->f;
		j++;
	}
}

int		ft_draw(t_cube *c)
{
	key_tab(c);
	c->x = 0;
	while (c->x < c->width)
	{
		initcamera(c);
		dda(c);
		dda2(c);
		dda3(c);
		calcoffsete(c);
		drawimg(c);
		(c->x)++;
	}
	sprite(c);
	if (c->save == 1)
	{
		create_bmp(c);
		error(19, c);
		c->save = 0;
	}
	else
		mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0);
	return (0);
}
