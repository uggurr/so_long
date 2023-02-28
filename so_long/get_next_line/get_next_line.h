/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:34:55 by uguyildi          #+#    #+#             */
/*   Updated: 2022/11/18 11:34:59 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

int		ft_gnl_strlen(char *str);
int		ft_gnl_strchr(char *buff, char c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*make_buff(char *buff);
char	*make_line(char *buff);
#endif
