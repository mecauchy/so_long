/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:56:21 by mecauchy          #+#    #+#             */
/*   Updated: 2023/03/10 18:47:44 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

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
	if (y >= content->width || x >= content->height)
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

static char	**ft_move_up(char **map)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x - 1, y))
	{
		if (map[x - 1][y] == 'E')
			ft_win();
		else if (map[x - 1][y] == 'C')
			content->map_info.nb_coin++;
		map[x][y] = '0';
		map[x - 1][y] = 'P';
		content->position_x--;
		content->nb_step++;
		content->mvmt_flag = UP;
	}
	return (map);
}

static char	**ft_move_down(char **map)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x + 1, y))
	{
		if (map[x + 1][y] == 'E')
			ft_win();
		else if (map[x + 1][y] == 'C')
			content->map_info.nb_coin++;
		map[x][y] = '0';
		map[x + 1][y] = 'P';
		content->position_x++;
		content->nb_step++;
		content->mvmt_flag = DOWN;
	}
	return (map);
}

static char	**ft_move_right(char **map)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x, y + 1))
	{
		if (map[x][y + 1] == 'E')
			ft_win();
		else if (map[x][y + 1] == 'C')
			content->map_info.nb_coin++;
		map[x][y] = '0';
		map[x][y + 1] = 'P';
		content->position_y++;
		content->nb_step++;
		content->mvmt_flag = RIGHT;
	}
	return (map);
}

static char	**ft_move_left(char **map)
{
	t_list	*content;
	int		x;
	int		y;

	content = _list();
	x = content->position_x;
	y = content->position_y;
	if (check_mov(x, y - 1))
	{
		if (map[x][y - 1] == 'E')
			ft_win();
		else if (map[x][y - 1] == 'C')
			content->map_info.nb_coin++;
		map[x][y] = '0';
		map[x][y - 1] = 'P';
		content->position_y--;
		content->nb_step++;
		content->mvmt_flag = LEFT;
	}
	return (map);
}

int	ft_key_hook(int keycode, t_list *content)
{
	/* edit all key WASD*/
	if (keycode == KEY_ESC)
		ft_exit();
	else if(keycode == KEY_Z)
		ft_move_up(content->map);
	else if (keycode == KEY_A)
		ft_move_left(content->map);
	else if (keycode == KEY_S)
		ft_move_down(content->map);
	else if (keycode == KEY_D)
		ft_move_right(content->map);
	draw_map(content->map);
	return (0);
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
	mlx_key_hook(content->win, ft_key_hook, content);
	draw_map(content->map);
	mlx_loop(content->mlx);
	return (0);
}
