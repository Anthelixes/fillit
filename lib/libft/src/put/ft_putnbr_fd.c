#include "libft.h"

inline static void	putlong(long n, int fd)
{
	if (n >= 10)
		putlong(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void				ft_putnbr_fd(int n, int fd)
{
	long	v;

	v = n;
	if (v < 0)
	{
		ft_putchar_fd('-', fd);
		v = -v;
	}
	putlong(v, fd);
}
