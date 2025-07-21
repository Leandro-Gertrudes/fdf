/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:41:40 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/31 20:51:46 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# ifndef CONFIG_H
#  define CONFIG_H

#  define WIN_WIDTH  1200
#  define WIN_HEIGHT 1000

# endif

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_view
{
	t_point	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		zoom;
	int		offset_x;
	int		offset_y;
	double	angle;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		scale;
	int		paint;
	int		fill;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		perspective;
	char	*projection;
}	t_view;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

typedef struct s_fill_vars
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
	int	w0;
	int	w1;
	int	w2;
}	t_fill_vars;

//commands
int		keyboard(int keycode, t_view *view);
int		print_commands(t_view *view);
int		mouse_hook(int button, int x, int y, t_view *vars);
void	command_color(t_view *view, int keycode);
void	zoom(t_view *view, int keycode);
void	move(t_view *view, int keycode);
void	error_fd(t_view *view);
//utils
int		win_close(t_view *view);
int		get_color(t_point a, t_view *view);
int		auto_paint(int z);
int		atoi_hex(const char *str);
void	clear_image(t_view *view);
void	free_map(t_view *view);
void	free_split(char **arr);
void	reset(t_view *view);
void	get_projection(t_view *view, double *x, double *y, double *z);
//parse and write
void	parse(char *file, t_view *view);
void	put_pixel_img(t_view *view, int x, int y, int color);
void	draw_map(t_view *view);
void	scale(t_view *view, int keycode);
void	projection(t_view *view);
void	init_bresenham(t_bresenham *b, t_point a, t_point b_point);
//rotate
int		direction(int a, int b);
void	rotate_x(double *y, double *z, double angle_x);
void	rotate_y(double *x, double *z, double angle_y);
void	rotate_z(double *x, double *y, double angle_z);
void	rr(t_view *view, int keycode);
//fill
void	fill_quad(t_view *view, int x, int y);
t_point	project_point(t_point p, t_view *view);

#endif
