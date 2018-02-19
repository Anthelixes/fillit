/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:58:34 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 14:58:35 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (str[i] == c2)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
