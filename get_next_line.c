/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:32 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/16 20:26:35 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_charcmp(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			if (i == 0)
				return (i + 1);
			return (i);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char			buff[SIZE + 1];
	ssize_t			i;
	char			*line;
	static char		*next_line = NULL;

	i = 1;
	line = next_line;
//	if (end != NULL)
//		free(end);
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	while (i > 0)
	{
		if (ft_charcmp(line, '\n'))
		{
			next_line = ft_strnext_line(line);
			return (ft_strcut(line));
		}
		i = read(fd, buff, SIZE);
		if (i <= 0 && line == NULL)
			return (NULL);
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (line)
		return (line);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	do
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		printf("[%d]>>>>%s", i, line);
		i++;
	}while (line);
	close(fd);
	return (0);
}
