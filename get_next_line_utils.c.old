/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:56:47 by tmongell          #+#    #+#             */
/*   Updated: 2022/01/07 22:39:46 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	if (!b)
		return (NULL);
	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i ++;
	}
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	first_size;

	j = 0;
	first_size = ft_strlen(dst);
	i = first_size;
	while (src[j] && i < dstsize - 1 && dstsize > 0)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	i --;
	if (dstsize > first_size)
		return (ft_strlen(src) + first_size);
	else
		return (ft_strlen(src) + dstsize);
}

//dependency : ft_strlen; ft_memset; ft_strlcat - 3
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memset(new_str, 0, len + 1);
	ft_strlcat (new_str, s1, len + 1);
	ft_strlcat (new_str, s2, len + 1);
	new_str[len] = '\0';
	return (new_str);
}

//dependency : ft_strlen - 1(common)
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	if (!dst)
		return (ft_strlen(src));
	i = 0;
	while (i < (int)dstsize && src)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i - 1] = '\0';
	return ((size_t)ft_strlen(src));
}
