/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:28 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/20 15:30:11 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define SIZE 1000000
# endif
# ifdef BUFFER_SIZE
#  define SIZE BUFFER_SIZE
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strcut(char *str);
char	*ft_strnext_line(char *str);
int		ft_charcmp(char *str, char c);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_lastline(char *str);

#include "stdio.h"

#endif