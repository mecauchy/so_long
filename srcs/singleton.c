/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:20:55 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/25 18:49:09 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_list	*_list(void)
{
	static t_list	list;
	static int		init = 0;
	
	if (init == 0)
	{
		ft_bzero(&list, sizeof(t_list));
		init++;
	}
	return (&list);
}
