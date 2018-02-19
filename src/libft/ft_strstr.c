/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:28:47 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:28:48 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, char *s2)
{
	int		cpt;
	int		cpt2;
	int		size;

	cpt = -1;
	cpt2 = 0;
	size = ft_strlen(s2);
	if (!size || !s1)
		return ((char *)s1);
	size--;
	while (s1[++cpt])
	{
		while (s2[cpt2] == s1[cpt + cpt2])
		{
			if (cpt2 == size)
				return ((char *)&s1[cpt]);
			cpt2++;
		}
		cpt2 = 0;
	}
	return (NULL);
}
