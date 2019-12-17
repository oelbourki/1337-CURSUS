/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:01:08 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:01:10 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		initcamera(t_cube *c)
{
	c->cx = 2 * c->x / ((double)c->width) - 1;
	c->rdx = c->dirx + c->plx * c->cx;
	c->rdy = c->diry + c->ply * c->cx;
	c->mapx = (int)c->px;
	c->mapy = (int)c->py;
	c->ddx = sqrt(1 + (c->rdy * c->rdy) / (c->rdx * c->rdx));
	c->ddy = sqrt(1 + (c->rdx * c->rdx) / (c->rdy * c->rdy));
	return (1);
}

int		dda(t_cube *c)
{
	if (c->rdx < 0)
	{
		c->stepx = -1;
		c->sdx = (c->px - c->mapx) * c->ddx;
	}
	else
	{
		c->stepx = 1;
		c->sdx = (-c->px + c->mapx + 1) * c->ddx;
	}
	if (c->rdy < 0)
	{
		c->stepy = -1;
		c->sdy = (c->py - c->mapy) * c->ddy;
	}
	else
	{
		c->stepy = 1;
		c->sdy = (-c->py + c->mapy + 1) * c->ddy;
	}
	return (1);
}

int		dda2(t_cube *c)
{
	c->hit = 0;
	while (c->hit == 0)
	{
		if (c->sdx < c->sdy)
		{
			c->sdx += c->ddx;
			c->mapx += c->stepx;
			c->side = 0;
		}
		else
		{
			c->sdy += c->ddy;
			c->mapy += c->stepy;
			c->side = 1;
		}
		if (c->map[c->mapx][c->mapy] == '1')
			c->hit = 1;
	}
	return (1);
}

int		dda3(t_cube *c)
{
	if (c->side == 0)
		c->pwdt = (c->mapx - c->px + (1 - c->stepx) / 2) / c->rdx;
	else
		c->pwdt = (c->mapy - c->py + (1 - c->stepy) / 2) / c->rdy;
	c->lh = (int)(c->height / c->pwdt);
	c->ds = -c->lh / 2 + c->height / 2;
	if (c->ds < 0)
		c->ds = 0;
	c->drawend = c->lh / 2 + c->height / 2;
	if (c->drawend >= c->height)
		c->drawend = c->height - 1;
	c->zbuffer[c->x] = c->pwdt;
	return (1);
}

int		calcoffsete(t_cube *c)
{
	if (c->side == 0)
		c->wx = c->py + c->pwdt * c->rdy;
	else
		c->wx = c->px + c->pwdt * c->rdx;
	c->wx -= floor((c->wx));
	c->texx = (int)(c->wx * (double)(c->texw));
	if (c->side == 0 && c->rdx > 0)
		c->texx = c->texw - c->texx - 1;
	if (c->side == 1 && c->rdy < 0)
		c->texx = c->texw - c->texx - 1;
	return (1);
}
