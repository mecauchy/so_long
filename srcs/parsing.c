/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:55:23 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/26 18:59:49 by mecauchy         ###   ########.fr       */
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

void	parsing(void)
{
	t_list	*content;

	content = _list();
	content->map = (char **)malloc(sizeof(char *) * (ft_size_map() + 1));
	if (!content->map)
		hasta_la_vista_baby();
	ft_make_map();
	check_corner();
}
