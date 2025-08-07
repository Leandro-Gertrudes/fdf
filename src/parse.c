#include "fdf.h"

static void	check_valid_line(char **split, int expected_width,
		t_view *view, char *line)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	if (count != expected_width)
	{
		ft_printf("Error: invalid map — inconsistent number of columns.\n");
		free_split(split);
		free(line);
		free_map(view);
		free(view);
		exit(1);
	}
}

static int	get_height(char *file)
{
	char	ch;
	int		fd;
	int		height;
	int		in_line;

	in_line = 0;
	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			height++;
			in_line = 0;
		}
		else
			in_line = 1;
	}
	if (in_line)
		height++;
	close(fd);
	return (height);
}

static int	get_width(char *file)
{
	char	ch;
	int		fd;
	int		width;

	width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &ch, 1) > 0)
	{
		if ((ch >= '0' && ch <= '9') || ch == '-')
		{
			width++;
			while (ch != ' ' && ch != '\n')
				read(fd, &ch, 1);
		}
		if (ch == '\n')
			break ;
	}
	close(fd);
	return (width);
}

static void	parse_2(t_view *view, char **split, int i)
{
	int		j;
	char	**z_color;

	j = 0;
	while (j < view->width)
	{
		z_color = ft_split(split[j], ',');
		view->map[i][j].x = j;
		view->map[i][j].y = i;
		view->map[i][j].z = ft_atoi(z_color[0]);
		if (z_color[1])
			view->map[i][j].color = atoi_hex(z_color[1]);
		else
			view->map[i][j].color = 0;
		free_split(z_color);
		j++;
	}
}

void	parse(char *file, t_view *view)
{
	int		i;
	int		fd;
	char	*line;
	char	**split;

	view->height = get_height(file);
	view->width = get_width(file);
	view->map = malloc(sizeof(t_point *) * view->height);
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_fd(view);
	line = get_next_line(fd);
	while (line != NULL)
	{
		view->map[i] = malloc(sizeof(t_point) * view->width);
		split = ft_split(line, ' ');
		check_valid_line(split, view->width, view, line);
		parse_2(view, split, i);
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
