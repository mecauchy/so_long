/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:20:55 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/23 20:27:35 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_mlx	*_mlx(void)
{
	static t_mlx	mlx;
	static int		init = 0;
	
	if (init == 0)
	{
		ft_bzero(&mlx, sizeof(t_mlx));
		init++;
	}
	return (&mlx);
}
