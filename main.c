/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:53:20 by tmongell          #+#    #+#             */
/*   Updated: 2022/01/11 12:24:14 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		nb_lines;
	char	*line;

	if (argc != 3)
		return (printf("error : args\nusage : %s <path> <nblines>\n", argv[0]));
	fd = open(argv[1], O_RDONLY);
	nb_lines = atoi(argv[2]);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		printf("[1;32m\tline %d : %s$\n[0m", i + 1, line);
		free(line);
		i ++;
	}
}
