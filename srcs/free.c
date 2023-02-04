/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:41:50 by mecauchy          #+#    #+#             */
/*   Updated: 2023/02/02 20:04:30 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_list *content)
{
    unsigned int	i;

    i = 0;
    if (!content)
        return;
    while (content->map[i])
    {
        free(content->map[i]);
        i++;
    }
    free(content->map);
    // content->map = NULL;
}

void	hasta_la_vista_baby(void)
{
	t_list	*content;
	
	content = _list();
	if (content->map)
		ft_free_map(content);
	if (content->img)
		mlx_destroy_image(content->mlx, content->img);
	if (content->win)
		mlx_destroy_window(content->mlx, content->win);
	exit(0);
}
