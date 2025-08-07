#include "fdf.h"

int	keyboard(int keycode, t_view *view)
{
	if (keycode == 65307)
		win_close(view);
	else if (keycode == 61 || keycode == 65451
		|| keycode == 65453 || keycode == 45)
		zoom(view, keycode);
	else if (keycode == 65361 || keycode == 65363
		|| keycode == 65362 || keycode == 65364)
		move(view, keycode);
	else if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100
		|| keycode == 113 || keycode == 101)
		rr(view, keycode);
	else if (keycode == 105 || keycode == 111)
		scale(view, keycode);
	else if (keycode == 114)
		reset(view);
	else if (keycode == 32 || keycode == 116)
		command_color(view, keycode);
	else if (keycode == 112)
		projection(view);
	return (0);
}

int	win_close(t_view *view)
{
	mlx_destroy_image(view->mlx, view->img);
	mlx_destroy_window(view->mlx, view->win);
	mlx_destroy_display(view->mlx);
	free(view->mlx);
	free_map(view);
	free(view);
	exit(0);
	return (0);
}

int	print_commands(t_view *view)
{
	mlx_string_put(view->mlx, view->win, 100, 100, 0x0FFFFFF,
		"FDF by: lgertrud");
	mlx_string_put(view->mlx, view->win, 500, 100, 0x0FFFFFF,
		view->projection);
	mlx_string_put(view->mlx, view->win, 100, 140, 0x0FFFFFF,
		"Rotation x and y: W A S D");
	mlx_string_put(view->mlx, view->win, 100, 160, 0x0FFFFFF,
		"Rotation z: Q E");
	mlx_string_put(view->mlx, view->win, 100, 180, 0x0FFFFFF,
		"Move: Arrows");
	mlx_string_put(view->mlx, view->win, 100, 200, 0x0FFFFFF,
		"Zoom: + -");
	mlx_string_put(view->mlx, view->win, 100, 220, 0x0FFFFFF,
		"Color: SPACE");
	mlx_string_put(view->mlx, view->win, 100, 240, 0x0FFFFFF,
		"paint: T");
	mlx_string_put(view->mlx, view->win, 100, 260, 0x0FFFFFF,
		"Scale: I O");
	mlx_string_put(view->mlx, view->win, 100, 280, 0x0FFFFFF,
		"Projection: P");
	mlx_string_put(view->mlx, view->win, 100, 320, 0x0FFFFFF,
		"Reset: R");
	mlx_string_put(view->mlx, view->win, 100, 340, 0x0FFFFFF,
		"Exit: ESC");
	return (0);
}

int	atoi_hex(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else
			break ;
		i++;
	}
	return (result);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
