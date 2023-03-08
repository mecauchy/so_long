/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:29:44 by mecauchy          #+#    #+#             */
/*   Updated: 2023/03/08 21:26:38 by mcauchy          ###   ########.fr       */
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

# define KEY_Z 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 0
# define KEY_ESC 53

# define IMG_W 32
# define IMG_H 32

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef	struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
}			t_img;

typedef struct s_map
{
	unsigned int		nb_collectible;
	unsigned int		nb_coin;
	unsigned int		nb_exit;
	unsigned int		nb_player;
}			t_map;

typedef struct s_list
{
	void				*mlx;
	void				*win;
	// void				*img;
	char				**map;
	char				*path;
	int					fd;
	unsigned int		width;
	unsigned int		height;
	int					position_x;
	int					position_y;
	int					image_width;
	int					image_height;
	t_img				*img;
	t_map				map_info;
}				t_list;


// singleton //

t_list	*_list(void);

// free //

void	hasta_la_vista_baby(void);

// parsing //
void	draw_map(char **map);
void	parsing(void);

// keyhook //

int	ft_key_hook(int keycode, t_list *content);

#endif
