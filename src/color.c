#include "fdf.h"

int	auto_paint(int z)
{
	if (z < 0)
		return (0x0000FF);
	else if (z >= 0 && z < 3)
		return (0x00BFFF);
	else if (z >= 3 && z < 5)
		return (0xFFFF00);
	else if (z >= 5 && z < 10)
		return (0x228B22);
	else if (z >= 10 && z < 15)
		return (0xADFF2F);
	else if (z >= 15 && z < 40)
		return (0x8B4513);
	else if (z >= 40 && z < 70)
		return (0xA9A9A9);
	else
		return (0xFFFFF);
}

int	get_color(t_point a, t_view *view)
{
	if (view->paint > 0 && view->fill < 0)
		return (auto_paint(a.z));
	if (a.color && view->fill < 0)
		return (a.color);
	else if (view->fill > 0)
		return (0x000000);
	else
		return (0xFFFFFF);
}

void	put_pixel_img(t_view *view, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = view->addr + (y * view->line_len + x * (view->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel_img(view, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
