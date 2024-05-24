#include <stdio.h>
#include <fcntl.h>

#include "libft.h"

#include "get_next_line.h"

int main(int ac, char *av[])
{
	char *line;

	line = get_next_line(0);
	while (ft_strncmp(line, av[1], ft_strlen(av[1])))
		line = get_next_line(0);
}
