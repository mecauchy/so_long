/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:55:59 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/26 00:08:14 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *next_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!next_str || !next_str[i])
		return (NULL);
	while (next_str[i] && next_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char *) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (next_str[i] && next_str[i] != '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	if (next_str[i] && next_str[i] == '\n')
	{
		str[i] = next_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *next_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!next_str)
	{
		next_str = (char *)malloc(sizeof(char));
		next_str[0] = '\0';
	}
	if (!next_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(next_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (next_str)
		while (next_str[++i])
			str[i] = next_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(next_str) + ft_strlen(buff)] = '\0';
	free(next_str);
	return (str);
}

char	*ft_read_to_next_str(int fd, char *next_str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	rd_bytes = -1;
	if (!buff)
		return (NULL);
	while (!(ft_strchr(next_str, '\n')) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if ((rd_bytes == -1) || (next_str == NULL && rd_bytes == 0))
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		next_str = ft_strjoin_gnl(next_str, buff);
	}
	free(buff);
	return (next_str);
}

char	*ft_new_str(char *next_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char *) * (ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free(next_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*next_str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_str = ft_read_to_next_str(fd, next_str);
	if (!next_str)
		return (NULL);
	ret = ft_get_line(next_str);
	next_str = ft_new_str(next_str);
	return (ret);
}
