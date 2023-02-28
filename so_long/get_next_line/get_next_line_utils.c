/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:35:18 by uguyildi          #+#    #+#             */
/*   Updated: 2022/11/18 11:35:21 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		x;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	x = -1;
	while (s1[++x])
		str[i++] = s1[x];
	x = -1;
	while (s2[++x])
		str[i++] = s2[x];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_gnl_strchr(char *buff, char c)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*make_line(char *buff)
{
	char	*a;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	a = malloc(sizeof(char) * (i + 2));
	if (!a)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		a[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		a[i] = '\n';
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*make_buff(char *buff)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_gnl_strlen(buff) - i + 1));
	if (!s)
		return (NULL);
	j = 0;
	i++;
	while (buff[i])
		s[j++] = buff[i++];
	s[j] = '\0';
	free(buff);
	return (s);
}
