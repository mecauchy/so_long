/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:56:21 by mecauchy          #+#    #+#             */
/*   Updated: 2023/03/07 19:23:30 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(void)
{
	t_list	*content;

	content = _list();
	mlx_destroy_window(content->mlx, content->win);
	exit(0);
}

int	check_mov(unsigned int x, unsigned int y)
{
	t_list	*content;

	content = _list();
	if (y < 0 || x < 0 || y >= content->width || x >= content->height)
		return (0);
	if (content->map[x][y] == '1')
		return (0);
	if (content->map[x][y] == 'E')
	{
		if (content->map_info.nb_coin == content->map_info.nb_collectible)
			return (1);
		else
			return (0);
	}
	if (content->map[x][y] == 'C' || content->map[x][y] == '0')
	{
		return (1);
	}
	return (0);
}

int	ft_win(void)
{
	write(1, "Congratulation ! Tou win\n", 25);
	write(1, "WINNER\n", 7);
	hasta_la_vista_baby();
	exit(EXIT_SUCCESS);
}

int	ft_exit(void)
{
	write(1, "Sorry, there is a problem...\n", 29);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_move_up(void)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x - 1, y))
	{
		if (content->map[x - 1][y] == 'E')
			ft_win();
		content->map[x][y] = '0';
		content->map[x - 1][y] = 'P';
	}
}

static void	ft_move_down(void)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x + 1, y))
	{
		if (content->map[x + 1][y] == 'E')
			ft_win();
		content->map[x][y] = '0';
		content->map[x + 1][y] = 'P';
	}
}

static void	ft_move_right(void)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x, y - 1))
	{
		if (content->map[x][y - 1] == 'E')
			ft_win();
		content->map[x][y] = '0';
		content->map[x][y - 1] = 'P';
	}
}

static void	ft_move_left(void)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x, y + 1))
	{
		if (content->map[x][y + 1] == 'E')
			ft_win();
		content->map[x][y] = '0';
		content->map[x][y + 1] = 'P';
	}
}

int	ft_key_hook(int keycode)
{
	printf("keycode = %d\n", keycode);
	if (keycode == KEY_ESC)
		ft_exit();
	else if(keycode == KEY_Z)
		ft_move_up();
	else if (keycode == KEY_A)
		ft_move_left();
	else if (keycode == KEY_S)
		ft_move_down();
	else if (keycode == KEY_D)
		ft_move_right();
	return (0);
}

void	draw_map(void)
{
	t_list				*content;
	unsigned int		x;
	unsigned int		y;

	content = _list();
	y = 0;
	x = 0;
	while (content->map[y])
	{
		x = 0;
		while (content->map[y][x])
		{
			if (content->map[y][x] == '1')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/wall.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (content->map[y][x] == 'P')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/player.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (content->map[y][x] == '0')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/background.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (content->map[y][x] == 'C')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/collectible.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			if (content->map[y][x] == 'E')
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

void	refresh_window(void)
{
	t_list	*content;

	content = _list();
	mlx_destroy_image(content->mlx, content->img);
	content->img = mlx_new_image(content->mlx, content->width * 32, content->height * 32);
}

int	main(int ac, char **av)
{
	t_list	*content;

	content = _list();
	if (ac != 2)
		return (0);
	content->path = av[1];
	content->fd = open(av[1], O_RDONLY);
	if (content->fd < 0)
		return (0);
	parsing();
	content->mlx = mlx_init();
	content->win = mlx_new_window(content->mlx, content->width * 32,
		content->height * 32, "so_long");
	mlx_hook(content->win, ON_DESTROY, 0, close_window, NULL);
	mlx_key_hook(content->win, ft_key_hook, NULL);
	// refresh_window();
	draw_map();
	mlx_loop(content->mlx);
	return (0);
	// appler keyhook pour les mouvements
}
