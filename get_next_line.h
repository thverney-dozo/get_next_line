/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:25:39 by thverney          #+#    #+#             */
/*   Updated: 2019/10/27 20:23:00 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		readline(char **line, char **str, int fd);
int		checkerror_gnl(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup_free(char *s1);
char	*ft_strjoin_free(char const *dst, char const *src, size_t n);
size_t		ft_strlen(const char *str);

#endif