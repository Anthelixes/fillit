/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:29:36 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:29:37 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ret;

	ret = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (n > 0)
	{
		n--;
		ret[n] = (unsigned char)c;
	}
	s = (void *)ret;
	return (s);
}
