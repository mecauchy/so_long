/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:29:44 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/23 20:28:26 by mecauchy         ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

// singleton//

t_mlx	*_mlx(void);

#endif
