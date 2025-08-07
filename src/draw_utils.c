#include "fdf.h"

void	get_projection(t_view *view, double *x, double *y, double *z)
{
	double	d;
	double	prev_x;
	double	prev_y;
	double	adj_z;
	double	factor;

	d = 500.0;
	prev_x = *x;
	prev_y = *y;
	if (view->perspective > 0)
	{
		adj_z = -*z;
		factor = d / (d + adj_z);
		*x *= factor;
		*y *= factor;
	}
	else
	{
		*x = (prev_x - prev_y) * cos(view->angle);
		*y = (prev_x + prev_y) * sin(view->angle) - *z;
	}
}

int	direction(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	init_bresenham(t_bresenham *b, t_point a, t_point b_point)
{
	b->dx = abs(b_point.x - a.x);
	b->dy = abs(b_point.y - a.y);
	b->sx = direction(a.x, b_point.x);
	b->sy = direction(a.y, b_point.y);
	b->err = b->dx - b->dy;
}
