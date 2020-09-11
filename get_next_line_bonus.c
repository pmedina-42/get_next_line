/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:14:08 by pmedina-          #+#    #+#             */
/*   Updated: 2020/09/11 13:37:27 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		isneg(char **s, char **line)
{
	if (ft_strchr(*s, '\0'))
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (0);
}

int		bytesneg(ssize_t *nby, char **s)
{
	if (*nby < 0)
	{
		if (*s != NULL)
		{
			free(*s);
			*s = NULL;
		}
		return (-1);
	}
	return (0);
}

int		aux(ssize_t nby, char **s, char **line)
{
	char	*vt;
	char	*vt2;

	if (!nby && !*s)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (bytesneg(&nby, &*s))
		return (-1);
	if ((vt = ft_strchr(*s, '\n')))
	{
		*vt = '\0';
		*line = ft_strdup(*s);
		vt2 = ft_strdup(vt + 1);
		free(*s);
		*s = vt2;
		return (1);
	}
	else if (isneg(&*s, &*line))
		return (0);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*mem;
	static char	*x[4096];
	ssize_t		nby;
	char		*vt;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
			(!(mem = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((nby = read(fd, mem, BUFFER_SIZE)) > 0)
	{
		mem[nby] = '\0';
		if (!x[fd])
			x[fd] = ft_strdup(mem);
		else
		{
			vt = ft_strjoin(x[fd], mem);
			free(x[fd]);
			x[fd] = vt;
		}
		if (ft_strchr(mem, '\n'))
			break ;
	}
	free(mem);
	mem = NULL;
	return (aux(nby, &x[fd], &*line));
}
