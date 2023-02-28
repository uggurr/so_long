/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:34:22 by uguyildi          #+#    #+#             */
/*   Updated: 2022/11/18 11:34:40 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*scan(int fd, char *stc)
{
	char	*buff;
	int		rb;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rb = 1;
	while (rb != 0 && !(ft_gnl_strchr(stc, '\n')))
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		stc = ft_gnl_strjoin(stc, buff);
	}
	free(buff);
	return (stc);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stc = scan(fd, stc);
	if (!stc)
		return (NULL);
	line = make_line(stc);
	stc = make_buff(stc);
	return (line);
}
