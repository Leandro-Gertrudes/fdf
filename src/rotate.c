#include "fdf.h"

void	rotate_x(double *y, double *z, double angle_x)
{
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(angle_x) - prev_z * sin(angle_x);
	*z = prev_y * sin(angle_x) + prev_z * cos(angle_x);
}

void	rotate_y(double *x, double *z, double angle_y)
{
	double	prev_x;
	double	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(angle_y) + prev_z * sin(angle_y);
	*z = -prev_x * sin(angle_y) + prev_z * cos(angle_y);
}

void	rotate_z(double *x, double *y, double angle_z)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle_z) - prev_y * sin(angle_z);
	*y = prev_x * sin(angle_z) + prev_y * cos(angle_z);
}
