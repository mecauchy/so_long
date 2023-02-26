/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:56:21 by mecauchy          #+#    #+#             */
/*   Updated: 2023/02/06 14:53:01 by mcauchy          ###   ########.fr       */
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

int	ft_win(void)
{
	write(1, "Congratulation ! Tou win\n", 25);
	write(1, "WINNER\n", 7);
	exit(EXIT_SUCCESS);
}

int	ft_exit(void)
{
	write(1, "Sorry, there is a problem...\n", 29);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_move_up(t_list *content, char position, int keyboard)
{
	unsigned int	x;
	unsigned int	y;

	if (content->map[x][y - 1] != '1')
		content->map[x][y - 1] 
	return ;
}

static void	ft_move_left(t_list *content, char position, int keyboard)
{

	if (position == 'x' && keyboard == KEY_A)
	{
		mlx_put_image_to_window(content->mlx, content->win, content->img->player_left,
			(content->position_x * IMG_W), (content->position_y * IMG_H));
		content->map[x][y] += 1;
	}
}

static void	ft_move_down(t_list *content, char position, int keyboard)
{
	if (position == 'y' && keyboard == KEY_S)
	{
		mlx_put_image_to_window(content->mlx, content->win, content->img->player_down,
			(content->position_x * IMG_W), (content->position_y * IMG_H));
	}
}

static void	ft_move_right(t_list *content, char position, int keyboard)
{
	if (position == 'x' && keyboard == KEY_D)
	{
		mlx_put_image_to_window(content->mlx, content->win, content->img->player_right,
			(content->position_x * IMG_W), (content->position_y * IMG_H));
	}
}

static void	ft_key(t_list *content, int keycode)
{
	t_list *content;

	content = _list;
	if (keycode == KEY_W)
		ft_move_down(content, 'y', UP);
	else if (keycode == KEY_A)
		ft_move_left(content, 'x', LEFT);
	else if (keycode == KEY_S)
		ft_move_down(content, 'y', DOWN);
	else if (keycode == KEY_D)
		ft_move_right(content, 'x', RIGHT);
}

int	ft_key_hook(int keycode)
{
	t_list	*content;

	content = _list();
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		ft_exit();

	// else if(keycode == KEY_W)
	// 	ft_
	// else if (keycode == KEY_A)
	// 	ft_move_left(content, 'x', LEFT);
	// else if (keycode == KEY_S)
	// 	ft_move_down(content, 'y', DOWN);
	// else if (keycode == KEY_D)
	// 	ft_move_right(content, 'x', RIGHT);

	if (keycode == 'E')
		ft_win();
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
	if (content->img)
		mlx_destroy_image(content->mlx, content->img);
	draw_map();
	mlx_loop(content->mlx);
	return (0);
	// appler keyhook pour les mouvements
}
