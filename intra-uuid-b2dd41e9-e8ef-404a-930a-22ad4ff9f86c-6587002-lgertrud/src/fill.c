/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:22:03 by lgertrud          #+#    #+#             */
/*   Updated: 2025/06/02 14:42:43 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_paint(t_point a, t_view *view)
{
	if (view->paint > 0)
		return (auto_paint(a.z));
	if (a.color)
		return (a.color);
	else
		return (0xFFFFFF);
}

void	fill_triangle(t_view *view, t_point p1, t_point p2, t_point p3)
{
	int			x;
	int			y;
	t_fill_vars	vars;

	vars.min_x = fmin(fmin(p1.x, p2.x), p3.x);
	vars.max_x = fmax(fmax(p1.x, p2.x), p3.x);
	vars.min_y = fmin(fmin(p1.y, p2.y), p3.y);
	vars.max_y = fmax(fmax(p1.y, p2.y), p3.y);
	y = vars.min_y;
	while (y <= vars.max_y)
	{
		x = vars.min_x;
		while (x <= vars.max_x)
		{
			vars.w0 = (p2.x - p1.x) * (y - p1.y) - (p2.y - p1.y) * (x - p1.x);
			vars.w1 = (p3.x - p2.x) * (y - p2.y) - (p3.y - p2.y) * (x - p2.x);
			vars.w2 = (p1.x - p3.x) * (y - p3.y) - (p1.y - p3.y) * (x - p3.x);
			if ((vars.w0 >= 0 && vars.w1 >= 0 && vars.w2 >= 0)
				|| (vars.w0 <= 0 && vars.w1 <= 0 && vars.w2 <= 0))
				put_pixel_img(view, x, y, get_paint(p1, view));
			x++;
		}
		y++;
	}
}

void	fill_quad(t_view *view, int x, int y)
{
	t_point	pa;
	t_point	pb;
	t_point	pc;
	t_point	pd;

	pa = project_point(view->map[y][x], view);
	pb = project_point(view->map[y][x + 1], view);
	pc = project_point(view->map[y + 1][x + 1], view);
	pd = project_point(view->map[y + 1][x], view);
	fill_triangle(view, pa, pb, pc);
	fill_triangle(view, pa, pc, pd);
}
