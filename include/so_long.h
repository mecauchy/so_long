/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:29:44 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/26 01:36:47 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H

# define SO_LONG_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_list
{
	void				*mlx;
	void				*win;
	void				*img;
	char				**map;
	char				*path;
	int					fd;
	unsigned int		width;
	unsigned int		height;
	int					image_width;
	int					image_height;
	t_player			player;
}				t_list;


// singleton //

t_list	*_list(void);

// free //

void	hasta_la_vista_baby(void);

// parsing //

void	parsing(void);

#endif
