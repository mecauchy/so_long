/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:55:23 by mecauchy          #+#    #+#             */
/*   Updated: 2023/03/08 21:32:55 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

unsigned int	ft_size_map(void)
{
	t_list			*content;
	char			*line;
	unsigned int	size;

	size = 0;
	content = _list();
	line = get_next_line(content->fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(content->fd);
	}
	free(line);
	content->height = size;
	close(content->fd);
	return (size);
}

void	ft_make_map(void)
{
	t_list	*content;
	char	*line;
	size_t	i;

	content = _list();
	i = 0;
	content->fd = open(content->path, O_RDONLY);
	line = get_next_line(content->fd);
	content->width = ft_strlen(line) - 1;
	while (line)
	{
		content->map[i] = ft_strdup(line);
		content->map[i] = ft_strtrim(content->map[i], "\n");
		if (!content->map[i])
			hasta_la_vista_baby();
		free(line);
		line = get_next_line(content->fd);
		i++;
	}
	content->map[i] = NULL;
	free(line);
	close(content->fd);
}

void	check_corner(void)
{
	t_list	*content;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	content = _list();
	while (x < content->width)
	{
		if (content->map[0][x] != '1' || content->map[content->height - 1][x] != '1')
			hasta_la_vista_baby();
		x++;
	}
	while (y < content->height)
	{
		if (content->map[y][0] != '1' || content->map[y][content->width - 1] != '1')
			hasta_la_vista_baby();
		y++;
	}
}

void	fill_mapinfo(void)
{
	t_list	*content;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	content = _list();
	while (y < content->height)
	{
		while (x < content->width)
		{
			if (content->map[y][x] == 'P')
			{
				content->position_x = y;
				content->position_y = x;
				content->map_info.nb_player++;
			}
			if (content->map[y][x] == 'C')
				content->map_info.nb_collectible++;
			if (content->map[y][x] == 'E')
				content->map_info.nb_exit++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_info(void)
{
	t_list	*content;

	content = _list();
	if (content->map_info.nb_player != 1 || content->map_info.nb_exit != 1 || content->map_info.nb_collectible == 0)
	{
		printf("nb_player = %d, nb_exit = %d, nb_collectible = %d\n", content->map_info.nb_player, content->map_info.nb_exit, content->map_info.nb_collectible);
		hasta_la_vista_baby();
	}
}

void	parsing(void)
{
	t_list	*content;

	content = _list();
	content->map = (char **)malloc(sizeof(char *) * (ft_size_map() + 1));
	if (!content->map)
		hasta_la_vista_baby();
	ft_make_map();
	check_corner();
	fill_mapinfo();
	check_info();
}

void	draw_map(char **map)
{
	t_list				*content;
	unsigned int		x;
	unsigned int		y;

	content = _list();
	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (x < content->width)
		{
			if (map[y][x] == '1')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/wall.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (map[y][x] == 'P')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/player.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (map[y][x] == '0')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/background.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (map[y][x] == 'C')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/collectible.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (map[y][x] == 'E')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/exit.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			x++;
		}
		y++;
	}
}
