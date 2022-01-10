/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:48:26 by tmongell          #+#    #+#             */
/*   Updated: 2022/01/07 23:03:26 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h> //might be needed by read(), but idk
# include <sys/uio.h> //might be needed by read(), but idk

//function from main file
char	*get_next_line(int fd);
int		ft_no_newline(char *str);
char	*ft_savebuff(char *line, char *buff);

//function from utils
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
