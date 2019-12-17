/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:02:04 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/29 18:02:06 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		key_press(int keycode, t_cube *c)
{
	if (keycode == 13)
		c->up = 1;
	if (keycode == 1)
		c->down = 1;
	if (keycode == 124)
		c->right = 1;
	if (keycode == 123)
		c->left = 1;
	if (keycode == 2)
		c->d0 = 1;
	if (keycode == 0)
		c->a = 1;
	if (keycode == 53)
		red(c);
	return (0);
}

int		key_release(int keycode, t_cube *c)
{
	if (keycode == 13)
		c->up = 0;
	if (keycode == 1)
		c->down = 0;
	if (keycode == 124)
		c->right = 0;
	if (keycode == 123)
		c->left = 0;
	if (keycode == 2)
		c->d0 = 0;
	if (keycode == 0)
		c->a = 0;
	return (1);
}

void	key_tab(t_cube *c)
{
	if (c->up == 1)
		key_up(c);
	if (c->down)
		key_down(c);
	if (c->right == 1)
		key_rotright(c);
	if (c->left == 1)
		key_rotleft(c);
	if (c->a == 1)
		key_rotleft(c);
	if (c->d0 == 1)
		key_rotright(c);
}
