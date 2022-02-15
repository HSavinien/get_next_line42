/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 04:08:59 by tmongell          #+#    #+#             */
/*   Updated: 2022/02/15 10:34:27 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>//===========================================================DEBUG

//functions from get_next_line.c
char	*get_next_line(int fd);
char	*save_buf(char *base_str, char *buf, int read_ret);
char	*save_leftover(char *str, char *old_leftover, int read_ret);
int		got_end_of_line(char *str);
int		multiple_line_in_str(char	*str);
//functions from get_next_line_utils.c
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
