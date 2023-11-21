/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:30 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/21 12:08:54 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
		join[i] = s1[i], i++;//! norm !
	if (i > 0)
		free(s1);
	while (s2 && s2[j])
		join[i + j] = s2[j], j++;//! norm !
	join[i + j] = '\0';
	return (join);
}

char	*ft_strcut(char *str)
{
	size_t		i;
	size_t		x;
	char		*line;

	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		i++;
	}
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	x = 0;
	while (x <= i)
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	free(str);
	return (line);
}

char	*ft_strnext_line(char *str)
{
	size_t		len;
	size_t		after;
	char		*next_line;
	size_t		i;

	next_line = NULL;
	len = ft_strlen(str);
	after = ft_charcmp(str, '\n');
	if (len == after)
		return (next_line);
	next_line = malloc(sizeof(char) * (len - after + 1));
	if (next_line == NULL)
		return (NULL);
	i = 0;
	while (after < len)
	{
		next_line[i] = str[after];
		after++;
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_lastline(char *str)
{
	size_t	i;
	size_t	x;
	char	*last;

	i = ft_strlen(str);
	last = malloc(sizeof(char) * (i + 1));
	if (!last)
		return (last);
	x = 0;
	while (x < i)
	{
		last[x] = str[x];
		x++;
	}
	last[x] = '\0';
	free(str);
	return (last);
}
