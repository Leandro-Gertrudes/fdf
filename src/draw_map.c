/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:36:20 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/31 21:06:38 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_point(t_point p, t_view *view)
{
	t_point	projected;
	double	x;
	double	y;
	double	z;

	x = (p.x - view->width / 2.0) * view->zoom;
	y = (p.y - view->height / 2.0) * view->zoom;
	z = (p.z * view->zoom) / view->scale;
	rotate_z(&x, &y, view->angle_z);
	rotate_x(&y, &z, view->angle_x);
	rotate_y(&x, &z, view->angle_y);
	get_projection(view, &x, &y, &z);
	projected.x = (int)(x + view->offset_x);
	projected.y = (int)(y + view->offset_y);
	projected.z = p.z;
	projected.color = p.color;
	return (projected);
}

void	draw_line(t_view *view, t_point a, t_point b)
{
	t_bresenham	b_vars;

	a = project_point(a, view);
	b = project_point(b, view);
	init_bresenham(&b_vars, a, b);
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel_img(view, a.x, a.y, get_color(a, view));
		b_vars.e2 = 2 * b_vars.err;
		if (b_vars.e2 > -b_vars.dy)
		{
			b_vars.err -= b_vars.dy;
			a.x += b_vars.sx;
		}
		if (b_vars.e2 < b_vars.dx)
		{
			b_vars.err += b_vars.dx;
			a.y += b_vars.sy;
		}
	}
	put_pixel_img(view, a.x, a.y, get_color(a, view));
}

void	draw_map(t_view *view)
{
	int	y;
	int	x;

	y = 0;
	while (y < view->height)
	{
		x = 0;
		while (x < view->width)
		{
			if (x < view->width - 1 && y < view->height - 1 && view->fill > 0)
				fill_quad(view, x, y);
			if (x < view->width - 1)
				draw_line(view, view->map[y][x], view->map[y][x + 1]);
			if (y < view->height - 1)
				draw_line(view, view->map[y][x], view->map[y + 1][x]);
			x++;
		}
		y++;
	}
}
