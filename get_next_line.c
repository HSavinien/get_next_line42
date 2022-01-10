/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:56:24 by tmongell          #+#    #+#             */
/*   Updated: 2022/01/10 16:25:24 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//============================================================DEBUG
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
//check that the content of a string don't contain a \n or \0.
int	ft_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i ++;
//	printf("debug(ft_no_newline,L26) : i = %d\n", i);//=========================DEBUG
	if (i == BUFFER_SIZE || i == 0)
		return (1);
	else
		return (0);
}

//add the content of the buffer to the return value
char	*ft_savebuff(char *line, char *buff)
{
	char	*old_line;

	old_line = line;
	line = ft_strjoin(line, buff);
	free(old_line);
	return (line);
}

// once the buffer contain the end of line/file, coppy the end of the line to
// the return value then move the rest of the buffer to buff[0]
char	*ft_finish_line(char *line, char *buff)
{
	char	end_line[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		end_line[i] = buff[i];
		i ++;
	}
	end_line[i] = buff[i];
	line = ft_savebuff(line, end_line);
//	if (buff[i])
	ft_strlcpy(buff, buff + i + 1, BUFFER_SIZE);
	buff[i + 1] = '\0';
	return (line);
}

//the main function
char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	line = malloc(1);
	line[0] = '\0';
	buff[BUFFER_SIZE] = '\0';
//	printf("debug(get_next_line,L73) : gnl initialized\n");//===================DEBUG
	while (ft_no_newline(buff))
	{
		line = ft_savebuff(line, buff);
//		printf("debug(get_next_line,L77) : line = %s\n", line);//===============DEBUG
		read(fd, buff, BUFFER_SIZE);
//		printf("debug(get_next_line,L79) : new buff = %s\n", buff);//===========DEBUG
	}
	line = ft_finish_line(line, buff);
	return (line);
}
