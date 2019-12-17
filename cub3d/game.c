/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:50:21 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:50:22 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_texture1(t_cube *c)
{
	if (!(c->xpms = (int*)mlx_get_data_addr(c->files, &c->bpp,
	&c->sl1, &c->e)))
		error(6, c);
	if (!(c->xpm[0] = (int*)mlx_get_data_addr(c->file[0], &c->bpp,
	&c->sl, &c->e)))
		error(6, c);
	if (!(c->xpm[1] = (int*)mlx_get_data_addr(c->file[1], &c->bpp,
	&c->sl, &c->e)))
		error(6, c);
	if (!(c->xpm[2] = (int*)mlx_get_data_addr(c->file[2], &c->bpp,
	&c->sl, &c->e)))
		error(6, c);
	if (!(c->xpm[3] = (int*)mlx_get_data_addr(c->file[3], &c->bpp,
	&c->sl, &c->e)))
		error(6, c);
}

void	init_mlx(t_cube *c)
{
	if (!(c->mlx_ptr = mlx_init()))
		error(1, c);
	if (c->save == 0)
	{
		if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->width,
		c->height, "learn")))
			error(2, c);
	}
	if (!(c->img_ptr = mlx_new_image(c->mlx_ptr,
	c->width, c->height)))
		error(3, c);
	if (!(c->s = (int*)mlx_get_data_addr(c->img_ptr,
	&c->bpp, &c->sl, &c->e)))
		error(4, c);
}

void	init_texture(t_cube *c)
{
	if (!(c->file[0] = mlx_xpm_file_to_image(c->mlx_ptr, c->no,
	&c->texw, &c->texh)))
		error(5, c);
	if (!(c->file[1] = mlx_xpm_file_to_image(c->mlx_ptr, c->so,
	&c->texw, &c->texh)))
		error(5, c);
	if (!(c->file[2] = mlx_xpm_file_to_image(c->mlx_ptr, c->we,
	&c->texw, &c->texh)))
		error(5, c);
	if (!(c->file[3] = mlx_xpm_file_to_image(c->mlx_ptr, c->ea,
	&c->texw, &c->texh)))
		error(5, c);
	if (!(c->files = mlx_xpm_file_to_image(c->mlx_ptr, c->ss,
	&c->xsw, &c->xsh)))
		error(5, c);
	init_texture1(c);
}

int		game(t_cube *c)
{
	initx(c);
	init_mlx(c);
	init_texture(c);
	if (c->save == 0)
	{
		mlx_hook(c->win_ptr, 2, 0, key_press, c);
		mlx_hook(c->win_ptr, 3, 0, key_release, c);
		mlx_hook(c->win_ptr, 17, 0, red, c);
	}
	return (1);
}

int		main(int argc, char **ar)
{
	t_cube	c;

	intit_most(&c);
	if (argc == 1)
		error(100, &c);
	if (!(c.p = ft_strnstr(ar[1], ".cub", ft_strlen(ar[1]))) || c.p[4] != '\0')
		error(101, &c);
	c.fd = open(ar[1], O_RDONLY);
	if (c.fd < 0)
		error(19, &c);
	if (argc == 3)
	{
		if (!ft_strcmp(ar[2], "--save"))
			c.save = 1;
		else
			error(102, &c);
	}
	else if (argc > 3)
		error(99, &c);
	get_the_cube(&c, c.fd);
	game(&c);
	mlx_loop_hook(c.mlx_ptr, ft_draw, &c);
	mlx_loop(c.mlx_ptr);
	return (0);
}
