/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:10:15 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:10:17 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_returnfunc(int neg, int nbr)
{
	if (neg == 1)
	{
		return (-nbr);
	}
	else
	{
		return (nbr);
	}
	return (nbr);
}

static int		ft_whilefunc(const char *str, int i)
{
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
	{
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int i;
	int nbr;
	int neg;

	nbr = 0;
	neg = 0;
	i = 0;
	i = ft_whilefunc(str, i);
	if (str[i] == '-')
	{
		neg = 1;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while ((str[i] != 0) && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	return (ft_returnfunc(neg, nbr));
}
