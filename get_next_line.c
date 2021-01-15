/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:06:47 by thverney          #+#    #+#             */
/*   Updated: 2019/10/27 20:23:01 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char*)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

int		checkerror_gnl(int fd, char **line)
{
	if (*line != NULL)
	{
		free(line);
		line = NULL;
	}
	if (fd == -1)
		return (-1);
	return (0);
}

int		readline(char **line, char **str, int fd)
{
	char buff[BUFFER_SIZE + 1];
	int ret;
	char *pos;
	char *pos2;

	while((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		pos = ft_strchr(buff, '\n');
		if (pos != NULL)
		{
			
			if (*str != NULL)
			{
				pos2 = ft_strchr(*str, '\n');
				if (pos2 == NULL)
				{
					pos[0] = '\0';
					*line = ft_strjoin(*str, buff);
					free(*str);
				}
				else
				{
					pos2[0] = '\0';
					*line = ft_strdup(*str);
					pos = ft_strjoin(pos2 + 1,buff);
					free(*str);
					*str = pos;
					break;
				}
			}
			else
			{
				pos[0] = '\0';
				*line = ft_strdup(buff);
			}
			*str = ft_strdup(pos + 1);
			break;
		}
		else
		{
			if (*str != NULL)
				*str = ft_strjoin_free(*str, buff, 1);
			else
				*str = ft_strdup(buff);
		}
	}
	if (ret == 0)
	{
		if (*str && (pos2 = ft_strchr(*str, '\n')) != NULL)
		{
			pos2[0] = '\0';
			*line = ft_strdup(*str);
			pos = ft_strdup(pos2 + 1);
			free(*str);
			*str = pos;
		}
		else if (*str && *str[0] != '\0')
		{
			*line = ft_strdup(*str);
			*str = NULL;
		}
		else
			*line = NULL;
	}
	return (0);
}

#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	static char *str = NULL;

	if (readline(line, &str, fd) != 0)
		return (-1);
	if (*line)
		return (1);
	return (0);
}