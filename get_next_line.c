/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:32 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/16 14:55:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_charcmp(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
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

char	*get_next_line(int fd)
{
	char			buff[SIZE + 1];
	size_t			i;
	char			*line;
	static char		*end = NULL;

	i = 1;
	line = end;
	while (i > 0)
	{
		i = read(fd, buff, SIZE);
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_charcmp(line, '\n'))
		{
			end = ft_strnext_line(line);
			return (ft_strcut(line));
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
