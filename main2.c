#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	int		ret;
	char	*line;

	(void)ac;
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%d, [%s]\n", ret, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	printf("FINI ! (%d)\n", ret);
	system("leaks a.out");
	return (0);
}
