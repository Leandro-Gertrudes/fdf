/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:50:54 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/31 20:06:54 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_view *view, int keycode)
{
	if (keycode == 61 || keycode == 65451)
		view->zoom++;
	else
		view->zoom--;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

void	move(t_view *view, int keycode)
{
	if (keycode == 65361)
		view->offset_x -= 10;
	else if (keycode == 65363)
		view->offset_x += 10;
	else if (keycode == 65362)
		view->offset_y -= 10;
	else if (keycode == 65364)
		view->offset_y += 10;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

int	mouse_hook(int button, int x, int y, t_view *view)
{
	(void)x;
	(void)y;
	if (button == 4)
		view->zoom++;
	else if (button == 5 && view->zoom > 1)
		view->zoom--;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
	return (0);
}

void	scale(t_view *view, int keycode)
	{
	if (keycode == 111)
		view->scale--;
	else if (keycode == 105)
		view->scale++;
	if (view->scale < 1)
		view->scale = 1;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

void	reset(t_view *view)
{
	view->angle = 0.523599;
	view->zoom = 10;
	view->offset_x = 500;
	view->offset_y = 500;
	view->angle_x = 0.0;
	view->angle_y = 0.0;
	view->angle_z = 0.0;
	view->scale = 1;
	view->paint = -1;
	view->fill = -1;
	view->perspective = -1;
	view->mlx = mlx_init();
	view->projection = "Isometric";
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}
