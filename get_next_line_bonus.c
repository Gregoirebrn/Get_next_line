/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdasdfasdfasget_next_line_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:32 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/21 12:08:25 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_charcmp(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			if (i == 0)
				return (i + 1);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	ssize_t			i;
	char			*line;
	static char		*next_line[OPEN_MAX + 1];

	i = 1;
	line = next_line[fd];
	if ((fd < 0 || fd > OPEN_MAX) || read(fd, NULL, 0) < 0)
		return (free(line), next_line[fd] = NULL, NULL);
	while (i > 0)
	{
		if (ft_charcmp(line, '\n'))
		{
			next_line[fd] = ft_strnext_line(line);
			return (ft_strcut(line));
		}
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0 && (!line))
			return (NULL);
		if (line && i == 0)
			return (next_line[fd] = NULL, ft_lastline(line));
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
	}
	return (NULL);
}
//
//#include "stdio.h"
//int	main(void)
//{
//	int		fd;
//	char	*line;
//	int		i;
//
//	i = 0;
//	line = NULL;
//	fd = open("test.txt", O_RDONLY);
//	if (fd == -1)
//		return (0);
//	do
//	{
//		if (line)
//			free(line);
//		line = get_next_line(fd);
//		printf("[%d]>>>>%s", i, line);
//		i++;
//	}while (line);
//	close(fd);
//	return (0);
//}
