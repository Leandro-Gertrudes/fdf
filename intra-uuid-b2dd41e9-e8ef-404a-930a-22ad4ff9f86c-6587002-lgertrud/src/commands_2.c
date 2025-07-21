/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:27 by lgertrud          #+#    #+#             */
/*   Updated: 2025/06/03 15:55:55 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rr(t_view *view, int keycode)
{
	if (keycode == 97)
		view->angle_y -= 0.05;
	else if (keycode == 100)
		view->angle_y += 0.05;
	else if (keycode == 115)
		view->angle_x -= 0.05;
	else if (keycode == 119)
		view->angle_x += 0.05;
	else if (keycode == 113)
		view->angle_z -= 0.05;
	else if (keycode == 101)
		view->angle_z += 0.05;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

void	command_color(t_view *view, int keycode)
{
	if (keycode == 116)
		view->fill *= -1;
	else
		view->paint *= -1;
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

void	projection(t_view *view)
{
	view->perspective *= -1;
	if (view->perspective < 0)
		view->projection = "Isometric";
	else
		view->projection = "Perspective";
	clear_image(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
}

void	error_fd(t_view *view)
{
	ft_printf("Error: cannot open file.\n");
	free_map(view);
	free(view);
	exit(1);
}
