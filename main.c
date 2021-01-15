/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:35:42 by thverney          #+#    #+#             */
/*   Updated: 2019/10/27 12:55:22 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;	
	char *line;
	int i;
	int k;

	k = 9;
	i = 0;
	(void)ac;
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (1)
	{	
		if ((i = get_next_line(fd, &line)) <= 0)
		{
			if (line)
				free(line);
			close(fd);
			return (0);
		}
		else 
		{
			printf("line : \"%s\" '%d'\n", line, i);
			free(line);
		}
	}
	while (1)
		;
	return (1);
}
