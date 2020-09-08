/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:24:44 by pmedina-          #+#    #+#             */
/*   Updated: 2020/09/08 12:33:54 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*memoria;
	size_t	i;

	i = ft_strlen(s1);
	if (!(memoria = malloc(i + 1)))
		return (NULL);
	ft_memcpy(memoria, s1, i);
	memoria[i] = '\0';
	return (memoria);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	c1;
	size_t	c2;
	size_t	i;

	i = 0;
	c2 = ft_strlen(s1);
	c1 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(x = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (c1 != c2)
	{
		x[i] = s1[c1];
		++i && ++c1;
	}
	c2 = 0;
	c1 = ft_strlen(s2);
	while (c2 != c1)
	{
		x[i++] = s2[c2++];
	}
	x[i] = '\0';
	return (x);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
