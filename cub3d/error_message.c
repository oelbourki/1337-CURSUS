/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:48:46 by oel-bour          #+#    #+#             */
/*   Updated: 2019/11/30 12:48:47 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	error3(int e, t_cube *c)
{
	if (e == 99)
		perror("a lot of argumnets\n");
	else if (e == 100)
		perror("you did not supplyed the map\n");
	else if (e == 101)
		perror("file must end with .cub\n");
	else if (e == 102)
		perror("you must enter --save or nothing\n");
	else if (e == 19 && c->fd < 0)
		perror("file not found\n");
	exit(0);
}

void	error4(int e, t_cube *c)
{
	if (e == 166)
		perror("Error\nmore than one sprite\n");
	else if (e == 205)
		perror("Error\na new line in map or a line started with one\n");
	else if (e == 203)
		perror("Error\nthere is a problem in order\n");
	else if (e == 207)
		perror("Error\nmap not found\n");
	else if ((e == 99) || (e == 100) || (e == 101) || (e == 102) || (e == 19))
		error3(e, c);
	red(c);
}

void	error2(int e, t_cube *c)
{
	if (e == 94)
		perror("Error\nduplicated NO key\n");
	else if (e == 93)
		perror("Error\nduplicated SO key\n");
	else if (e == 92)
		perror("Error\nduplicated WE key\n");
	else if (e == 91)
		perror("Error\nduplicated EA key\n");
	else if (e == 90)
		perror("Error\nduplicated S key\n");
	else if (e == 89)
		perror("Error\nduplicated R key\n");
	else if (e == 88)
		perror("Error\nduplicated C key\n");
	else if (e == 87)
		perror("Error\nduplicated F key\n");
	else if (e == 86)
		perror("Error\nduplicated key in same line\n");
	else if (e == 85)
		perror("Error\nproblem in the line you supplied\n");
	else if (e == 84)
		perror("Error\nduplicated lines with same key\n");
	error4(e, c);
}

void	error1(int e, t_cube *c)
{
	if (e == 105)
		perror("Error\nnegative value\n");
	else if (e == 7)
		perror("image does not destroyed properly\n");
	else if (e == 3)
		perror("problem in new image\n");
	else if (e == 25)
		perror("the screen shot does not created\n");
	if (e == 15)
		perror("Error\nproblem in map lines or duplicated player\n");
	else if (e == 16)
		perror("Error\nmissing data in info.cub\n");
	else if (e == 98)
		perror("Error\nproblem in resolution\n");
	else if (e == 96)
		perror("Error\nproblem in floor data\n");
	else if (e == 97)
		perror("Error\nproblem in ceiling data\n");
	else if (e == 95)
		perror("Error\nunkown key or duplicated line with same key\n");
	else if (e == 119)
		perror("Error\nnegative value in color rgb or more than 255\n");
	else if (e == 120)
		perror("Error\nkey or key data is not good\n");
	error2(e, c);
}

void	error(int e, t_cube *c)
{
	if (e == 1)
		perror("problem mlx init\n");
	else if (e == 2)
		perror("problem in new window\n");
	else if (e == 3)
		perror("problem in new image\n");
	else if (e == 4)
		perror("mlx_xpm_file_to_image\n");
	else if (e == 5)
		perror("mlx_xpm_file_to_image for texture\n");
	else if (e == 6)
		perror("mlx_get_data_addr\n");
	else if (e == 11)
		perror("problem in allocation\n");
	if (e == 64564)
		perror("Error\nnegative value\n");
	else if (e == 9)
		perror("ft_split\n");
	else if (e == 10)
		perror("ft_strdup\n");
	else if (e == 125)
		perror("Error\n in map\n");
	else if (e == 126)
		perror("Error\n there is no player\n");
	error1(e, c);
}
