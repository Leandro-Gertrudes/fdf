/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:40:16 by lgertrud          #+#    #+#             */
/*   Updated: 2025/06/03 17:51:20 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_view *view)
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
	view->projection = "Isometric";
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->addr = mlx_get_data_addr(view->img, &view->bpp,
			&view->line_len, &view->endian);
}

void	free_map(t_view *view)
{
	int	i;

	i = 0;
	while (i < view->height)
	{
		free(view->map[i]);
		i++;
	}
	free(view->map);
}

int	main(int argc, char **argv)
{
	t_view	*view;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <file.fdf>\n", 24);
		return (1);
	}
	view = malloc(sizeof(t_view));
	parse(argv[1], view);
	init_view(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
	mlx_mouse_hook(view->win, mouse_hook, view);
	mlx_key_hook(view->win, keyboard, view);
	mlx_hook(view->win, 17, 0, win_close, view);
	mlx_loop(view->mlx);
	free_map(view);
	free(view);
}
