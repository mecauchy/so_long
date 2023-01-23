/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:56:21 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/23 20:39:54 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(void)
{
	t_mlx	*ptr;
	
	ptr = _mlx();
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}

int	main(void)
{
	t_mlx	*mlx;
	
	mlx = _mlx();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, NULL);
	mlx_loop(mlx->mlx);
	
	return (0);
}
