/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:08:57 by atote             #+#    #+#             */
/*   Updated: 2020/02/08 18:49:37 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../minilibx_macos/mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define BUTTON_W 13
# define BUTTON_S 1
# define BUTTON_A 0
# define BUTTON_D 2
# define ESC 53
# define BUTTON_Q 12
# define BUTTON_E 14
# define BUTTON_UP 126
# define BUTTON_DOWN 125
# define BUTTON_LEFT 123
# define BUTTON_RIGHT 124
# define BUTTON_I 34
# define BUTTON_P 35
# define BUTTON_MINUS 27
# define BUTTON_PLUS 24
# define ENTER 36
# define BUTTON_Z 6
# define BUTTON_X 7
# define BUTTON_1 18
# define SPACE 49

# define HEIGHT 2500
# define WIDTH 1300

typedef struct		s_img
{
	void			*p_img;
	char			*im_d;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				b;
	int				g;
}					t_color;

typedef struct		s_coord
{
	double			xcrd;
	double			ycrd;
	double			zcrd;
	t_color			*clr;
}					t_coord;

typedef struct		s_param
{
	void			*win;
	void			*conn;
	int				endi;
	int				endj;
	double			**nbrs;
	double			ang_w;
	double			ang_r;
	double			ang_z;
	int				hei;
	int				wid;
	int				def_x;
	int				def_y;
	int				def_size;
	int				s;
	double			count;
	int				pnts_amount;
	int				i;
	int				j;
	double			dx;
	double			dy;
	double			xdraw;
	double			ydraw;
	double			maxh;
	double			minh;
	double			d_grad;
	char			***cvet;
	int				press_1;
	int				press_2;
	int				pre_y;
	int				pre_x;
	int				flag;
	int				endmax;
	t_coord			**crd;
	t_img			im;
	t_color			clr;
	char			*projection;
}					t_param;

double				stepen(double in, int st);
int					fact(int st);
double				get_sin(double rad);
double				get_cos(double rad);
void				reading_map(int fd, char *line, double **nbrs, t_param *p);
void				init_p(t_param *p);
void				fill_pix(t_param *p, int x, int y);
void				draw_all(t_param *p);
void				rotate(t_param *p);
void				take_pix_color(t_param *p, int j, int i);
void				take_pix_map(t_param *p);
void				init_def_p(t_param *p);
void				calculate_ver(t_param *p);
void				calculate_gor(t_param *p);
void				fill_pix_gor(t_param *p, int x, int y);
void				fill_pix_ver(t_param *p, int x, int y);
int					mouse_press(int key, int x, int y, void *ptr);
int					mouse_release(int key, int x, int y, void *ptr);
int					mouse_motion(int x, int y, void *ptr);
int					sixteen_to_ten(char *str, int p);
void				draw_gor(t_param *p);
void				draw_ver(t_param *p);
void				rotate_help(t_param *p, double tmp);
void				find_size(int *fd, char *line, t_param *p);

#endif
