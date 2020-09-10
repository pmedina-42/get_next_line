/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:05:34 by jaleman           #+#    #+#             */
/*   Updated: 2020/09/10 13:06:53 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int	fd2;
	int ret;
	int line;
	char *buff;
	int	i;

	line = 0;
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		i = 1;
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, i++, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, i++, buff);
		if (ret == -1)
			printf("ERROR\n");
		else if (ret == 0)
			printf("EOF\n");
		fd2 = open(argv[2], O_RDONLY);
		close(fd);
		fd = fd2;
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, i++, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, i++, buff);
		if (ret == -1)
			printf("ERROR\n");
		if (ret == 0)
			printf("EOF\n");
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		close(fd);
	}
	return (0);
}
