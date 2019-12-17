/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:02:16 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:02:18 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	key_up(t_cube *c)
{
	if (c->map[(int)(c->px + c->dirx * c->movespeed)][(int)c->py] == '0')
		c->px += c->dirx * c->movespeed - 0.001;
	if (c->map[(int)(c->px)][(int)(c->py + c->diry * c->movespeed)] == '0')
		c->py += c->diry * c->movespeed - 0.001;
}

void	key_down(t_cube *c)
{
	if (c->map[(int)(c->px - c->dirx * c->movespeed)][(int)c->py] == '0')
		c->px -= c->dirx * c->movespeed;
	if (c->map[(int)(c->px)][(int)(c->py - c->diry * c->movespeed)] == '0')
		c->py -= c->diry * c->movespeed;
}

void	key_rotright(t_cube *c)
{
	c->odx = c->dirx;
	c->dirx = c->dirx * cos(-c->rotspeed) - c->diry * sin(-c->rotspeed);
	c->diry = c->odx * sin(-c->rotspeed) + c->diry * cos(-c->rotspeed);
	c->oldplx = c->plx;
	c->plx = c->plx * cos(-c->rotspeed) - c->ply * sin(-c->rotspeed);
	c->ply = c->oldplx * sin(-c->rotspeed) + c->ply * cos(-c->rotspeed);
}

void	key_rotleft(t_cube *c)
{
	c->odx = c->dirx;
	c->dirx = c->dirx * cos(c->rotspeed) - c->diry * sin(c->rotspeed);
	c->diry = c->odx * sin(c->rotspeed) + c->diry * cos(c->rotspeed);
	c->oldplx = c->plx;
	c->plx = c->plx * cos(c->rotspeed) - c->ply * sin(c->rotspeed);
	c->ply = c->oldplx * sin(c->rotspeed) + c->ply * cos(c->rotspeed);
}
