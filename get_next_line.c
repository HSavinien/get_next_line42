/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:47:19 by tmongell          #+#    #+#             */
/*   Updated: 2022/01/11 15:19:39 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//============================================================DEBUG
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	line_not_finished(char *buff)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			return (0);
		i ++;
	}
	return (1);
}

//note : I should free old_line befor the return, but malloc won't let me ;(
char	*ft_save_buff(char *line, char *buff)
{
	char	*old_line;

	old_line = line;
	line = ft_strjoin(line, buff);
//	free(old_line);
	return (line);
}

char	*ft_finish_line(char *buff, char *line, char *leftover)
{
	char	end_of_line[BUFFER_SIZE + 1];
	char	*true_line;
	int		i;
	int		j;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		end_of_line[i] = buff[i];
		i ++;
	}
	end_of_line[i] = buff[i];
	true_line = ft_strjoin(line, end_of_line);
	j = 0;
	while (i < BUFFER_SIZE && buff[i])
	{
		leftover[j] = buff[i];
		i ++;
		j ++;
	}
	leftover[j] = '\0';
//	free(line);
	return (true_line);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*line;

	line = ft_strdup(leftover);
	buff[BUFFER_SIZE] = '1';
	while (line_not_finished(buff) || buff[BUFFER_SIZE])
	{
		buff[BUFFER_SIZE] = '\0';
		line = ft_save_buff(line, buff);
		read(fd, buff, BUFFER_SIZE);
	}
	line = ft_finish_line(buff, line, leftover);
	return (line);
}
