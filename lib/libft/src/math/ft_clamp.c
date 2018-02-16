double		ft_clamp(double i, double a, double b)
{
	if (i < a)
		i = a;
	if (i > b)
		i = b;
	return (i);
}
