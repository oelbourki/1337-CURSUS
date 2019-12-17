/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:29:34 by oel-bour          #+#    #+#             */
/*   Updated: 2019/12/01 22:29:35 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <errno.h>
# define BYTES_PER_PIXEL     3
# define FILE_HEADER_SIZE    14
# define INFO_HEADER_SIZE    40

typedef struct	s_cube
{
	int			width;
	int			height;
	char		*holder[9];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*ss;
	char		pos;
	int			lx;
	int			ly;
	int			f;
	int			c;
	char		**map1;
	char		**map;
	char		d;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	double		px;
	double		py;
	double		dirx;
	double		diry;
	double		plx;
	double		ply;
	int			x;
	double		cx;
	double		rdx;
	double		rdy;
	int			mapx;
	int			mapy;
	double		sdx;
	double		sdy;
	double		ddx;
	double		ddy;
	double		pwdt;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lh;
	double		odx;
	double		oldplx;
	int			up;
	int			down;
	int			left;
	int			right;
	int			a;
	int			d0;
	double		movespeed;
	double		rotspeed;
	int			h;
	int			ds;
	int			drawend;
	int			color;
	double		wx;
	int			texx;
	int			texy;
	int			*s;
	int			bpp;
	int			sl;
	int			e;
	void		*file[5];
	int			*xpm[5];
	int			texw;
	int			texh;
	double		sx;
	double		sy;
	int			xsw;
	int			xsh;
	void		*files;
	int			*xpms;
	int			zbuffer[5125];
	double		sxr;
	double		syr;
	double		inv;
	double		transx;
	double		transy;
	int			screensx;
	int			sh;
	int			dsy;
	int			drawendy;
	int			sw;
	int			dsx;
	int			drawendx;
	int			save;
	int			flag;
	int			l;
	char		*p;
	int			flag1;
	int			r;
	int			g;
	int			b;
	int			sl1;
	int			flag2;
	int			tabx[5000];
	int			taby[5000];
	int			flag3;
	int			fd;
	int			k;
	int			old;
}				t_cube;
static int g_size = 5;
static int g_check[9] = {0};
int				get_next_line(int fd, char **line);
int				initcamera(t_cube *c);
int				dda(t_cube *c);
int				dda2(t_cube *c);
int				dda3(t_cube *c);
int				calcoffsete(t_cube *c);
int				key_press(int keycode, t_cube *c);
int				key_release(int keycode, t_cube *c);
void			key_tab(t_cube *c);
void			key_up(t_cube *c);
void			key_down(t_cube *c);
void			key_rotright(t_cube *c);
void			key_rotleft(t_cube *c);
void			sprite1(t_cube *c);
void			sprite(t_cube *c);
void			drawimg(t_cube *c);
void			initimage(t_cube *c);
int				ft_draw(t_cube *c);
void			error(int e, t_cube *c);
int				red(t_cube *c);
int				free_split(char **h);
int				get_r(t_cube *h);
void			get_c(t_cube *h);
void			get_f(t_cube *h);
int				get_path_no(t_cube *h);
int				get_path_so(t_cube *h);
int				get_path_we(t_cube *h);
int				get_path_ea(t_cube *h);
int				get_path_ss(t_cube *h);
void			free_structure(t_cube *h);
int				get_the_cube(t_cube *h, int fd);
void			fill_line(t_cube *h, char *line, int *i);
int				get_info_help(t_cube *h, char *line);
int				ft_strlen1(char *line, t_cube *h);
int				ft_strlen2(char *line, t_cube *h, int i, int j);
void			initx(t_cube *c);
void			init_dir(t_cube *c);
void			intit_most(t_cube *c);
void			intit_most1(t_cube *c);
unsigned char	*create_bitmap_info_header(int height, int width);
unsigned char	*create_bitmap_file_header(int height, int width,
int padding_size);
void			generate_bitmap_image(t_cube *all, int height, int width);
void			write_rgb(t_cube *all, int height, int width, int fd);
int				create_bmp(t_cube *all);
int				ft_strcmp(const char *s1, const char *s2);
void			free_error(char **s, int e, t_cube *h);
void			free_error1(char **s, char **s1, int e, t_cube *h);
char			*give(char *s);
int				checklinex(char *s, char *set);
void			check_info(t_cube *h);
void			ft_free(void *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t old, size_t size);
#endif
