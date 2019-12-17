/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:05:51 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:05:53 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sprite1(t_cube *c)
{
	int x;
	int y;
	int d;
	int texx;
	int texy;

	x = c->dsx - 1;
	while (++x < c->drawendx)
	{
		texx = ((256 * (x - (-c->sw / 2 + c->screensx))
		* c->xsw / c->sw)) / 256;
		if (c->transy > 0 && x > 0 && x < c->width
		&& c->transy < c->zbuffer[x] + 0.7)
		{
			y = c->dsy - 1;
			while (++y < c->drawendy)
			{
				d = y * 256 - c->height * 128 + c->sh * 128;
				texy = ((d * c->xsh) / c->sh) / 256;
				c->color = c->xpms[c->xsw * texy + texx];
				if ((c->color & 0x00FFFFFF) != 0)
					c->s[y * c->width + x] = c->color;
			}
		}
	}
}

void	sprite(t_cube *c)
{
	c->sxr = c->sx - c->px;
	c->syr = c->sy - c->py;
	c->inv = (1.0) / (double)(c->plx * c->diry - c->dirx * c->ply);
	c->transx = c->inv * (c->sxr * c->diry - c->syr * c->dirx);
	c->transy = c->inv * (-c->sxr * c->ply + c->syr * c->plx);
	c->screensx = (int)((c->width / 2) * (1 + c->transx / c->transy));
	c->sh = fabs(c->height / c->transy);
	c->dsy = -c->sh / 2 + c->height / 2;
	if (c->dsy < 0)
		c->dsy = 0;
	c->drawendy = c->sh / 2 + c->height / 2;
	if (c->drawendy >= c->height)
		c->drawendy = c->height - 1;
	c->sw = fabs(c->height / c->transy);
	c->dsx = -c->sw / 2 + c->screensx;
	if (c->dsy < 0)
		c->dsx = 0;
	c->drawendx = c->sw / 2 + c->screensx;
	if (c->drawendx >= c->width)
		c->drawendx = c->width - 1;
	sprite1(c);
}
