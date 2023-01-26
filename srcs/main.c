/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:56:21 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/26 19:00:37 by mecauchy         ###   ########.fr       */
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

//int	ft_win(t_list *data)
//{
//	write(1, "Congratulation ! Tou win\n", 25);
//	write(1, "WINNER\n", 7);
//	exit(EXIT_SUCCESS);
//}

//int	ft_exit(t_list *data)
//{
//	write(1, "Sorry, there is a problem...\n", 29);
//	write(1, "Error\n", 6);
//	exit(EXIT_FAILURE);
//}

//static void	ft_player_move_to_mlx(t_list *data, char *position, int keyboard)
//{
//	if (position == 'y' && keyboard == UP)
//	{
//		mlx_put_image_to_window(data);
//		(data->position_x * ...), (data->position_y * ...);
//	}
//	if (position == 'x' && keyboard == LEFT)
//	{
//		mlx_put_image_to_window(data);
//		(data->position_x * ...), data->position_y * ...);
//	}
//	if (position == 'y' && keyboard == DOWN)
//	{
//		mlx_put_image_to_window(data);
//		(data->position_x * ...), data->position_y * ...);
//	}
//	if (position == 'x' && keyboard == RIGHT);
//		mlx_put_image_to_window(data);
//		(data->position_x * ...), data->position_y * ...);
//}

//int	ft_key_hook(int keycode)
//{
//	t_list	*data;

//	data = _list();
//	printf("%d\n", keycode);
//	if (keycode= ESC)
//		ft_exit(data);
//	else if(keycode == W)
//		ft_move(data, 'y', UP);
//	else if (keycode == A)
//		ft_move(data, 'x', LEFT);
//	else if (keycode == S)
//		ft_move(data, 'y', DOWN);
//	else if (keycode == D)
//		ft_move(data, 'x', RIGHT);
//	if (keycode == E)
//		ft_win(data);
//	return (0);
//}

//int	ft_key_hook(int keycode)
//{
//}

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
			else if (content->map[y][x] == 'P')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/player.xpm",
					&content->image_width, &content->image_height);
				mlx_put_image_to_window(content->mlx, content->win, content->img,
					x * content->image_width, y * content->image_height);
			}
			else if (content->map[y][x] == 'C')
			{
				content->img = mlx_xpm_file_to_image(content->mlx, "texture_xpm/collectible.xpm",
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
	//mlx_key_hook(content->win, ft_key_hook, NULL);
	if (content->img)
		mlx_destroy_image(content->mlx, content->img);
	draw_map();
	mlx_loop(content->mlx);
	return (0);
}
