/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 04:07:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/02/11 01:36:43 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//============================================================DEBUG
#include <string.h>//===========================================================DEBUG
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*leftover;
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strdup(leftover);
	if (multiple_line_in_str(leftover))
	{
		leftover = save_leftover(line, leftover);
		return (line);
	}
	buf[BUFFER_SIZE] = '\0';
	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret <= 0)
	{
		free(line);
		return (NULL);
	}
	while (!got_end_of_line(buf) && read_ret > 0)
	{
		line = save_buf(line, buf, read_ret);
		read_ret = read(fd, buf, BUFFER_SIZE);
	}
	line = save_buf(line, buf, read_ret);
	leftover = save_leftover(buf, leftover);
	return (line);
}

//used on the buf. test if the str get either a /n or /0 in it, which would mean
//the line is over
int	got_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i ++;
	}
	return (0);
}

//used on the leftover, to see if we should read anything. differ from
//got_end_of_line by the fact it does not see \0 as end of line.
int	multiple_line_in_str(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

char	*save_buf(char *base_str, char *buf, int read_ret)
{
	char	*new_str;
	int		base_size;
	int		buf_size;

	base_size = ft_strlen(base_str);
	buf_size = 0;
	while (buf[buf_size] && buf[buf_size] != '\n' && read_ret-- )
		buf_size ++;
	if (buf[buf_size] == '\n')
		buf_size ++;
	new_str = malloc(base_size + buf_size + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, base_str, base_size + 1);
	ft_strlcpy(new_str + base_size, buf, buf_size + 1);
	free(base_str);
	return (new_str);
}

char	*save_leftover(char *str, char *old_leftover)
{
	char	*leftover;
	int		i;
	(void)	old_leftover;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	leftover = ft_strdup(str + i + 1);
	str[i + 1] = '\0';
	if (!*leftover)
	{
		free(leftover);
		leftover = NULL;
	}
	if (old_leftover)
		free(old_leftover);
	return (leftover);
}
