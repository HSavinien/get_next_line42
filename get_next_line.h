/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 04:08:59 by tmongell          #+#    #+#             */
/*   Updated: 2022/03/08 08:49:04 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

//functions from get_next_line.c
char	*get_next_line(int fd);
char	*save_buf(char *base_str, char *buf, int read_ret);
char	*save_leftover(char *str, char *old_lftover);
int		got_end_of_line(char *str);
int		multiple_line_in_str(char	*str);
void	*do_free(void *ptr);
//functions from get_next_line_utils.c
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
#endif
