#include "libft.h"
#include <stdlib.h>

int		ft_die(char *reason)
{
	ft_putstr(reason);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
