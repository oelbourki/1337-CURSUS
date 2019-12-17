/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:51:57 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:51:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	intit_most1(t_cube *c)
{
	c->mlx_ptr = NULL;
	c->win_ptr = NULL;
	c->img_ptr = NULL;
	c->s = NULL;
	c->file[0] = NULL;
	c->file[1] = NULL;
	c->file[2] = NULL;
	c->file[3] = NULL;
	c->file[4] = NULL;
	c->xpm[0] = NULL;
	c->xpm[1] = NULL;
	c->xpm[2] = NULL;
	c->xpm[3] = NULL;
	c->xpm[4] = NULL;
	c->files = NULL;
	c->xpms = NULL;
	c->flag = 1;
	c->f = 0;
	c->c = 0;
	c->width = 0;
	c->height = 0;
	c->save = 0;
	c->flag1 = 0;
	c->flag2 = 0;
	c->flag3 = 0;
}

void	intit_most(t_cube *c)
{
	c->holder[0] = NULL;
	c->holder[1] = NULL;
	c->holder[2] = NULL;
	c->holder[3] = NULL;
	c->holder[4] = NULL;
	c->holder[5] = NULL;
	c->holder[6] = NULL;
	c->holder[7] = NULL;
	c->holder[8] = NULL;
	c->no = NULL;
	c->so = NULL;
	c->we = NULL;
	c->ea = NULL;
	c->ss = NULL;
	c->map1 = NULL;
	c->map = NULL;
	c->r = 0;
	c->g = 0;
	c->b = 0;
	intit_most1(c);
}

void	init_dir1(t_cube *c)
{
	if (c->pos == 'S')
	{
		c->dirx = -1;
		c->diry = 0;
		c->plx = 0;
		c->ply = 0.66;
		c->rotspeed = 0.02 * 3.0;
	}
	else if (c->pos == 'E')
	{
		c->dirx = 0;
		c->diry = 1;
		c->plx = 0.66;
		c->ply = 0;
		c->rotspeed = 0.02 * 3.0;
	}
}

void	init_dir(t_cube *c)
{
	if (c->pos == 'W')
	{
		c->dirx = 0;
		c->diry = -1;
		c->plx = 0.66;
		c->ply = 0;
		c->rotspeed = -0.02 * 3.0;
	}
	else if (c->pos == 'N')
	{
		c->dirx = 1;
		c->diry = 0;
		c->plx = 0;
		c->ply = 0.66;
		c->rotspeed = -0.02 * 3.0;
	}
	else
		init_dir1(c);
}

void	initx(t_cube *c)
{
	c->movespeed = 0.02 * 5.0;
	init_dir(c);
	c->map = c->map1;
	c->up = 0;
	c->down = 0;
	c->right = 0;
	c->left = 0;
	c->a = 0;
	c->d0 = 0;
}
