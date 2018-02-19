/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:23:56 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:23:57 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		size;
	int		cpt;

	cpt = 0;
	size = ft_strlen(s1);
	while (s2[cpt] && n--)
		s1[size++] = s2[cpt++];
	s1[size] = '\0';
	return (s1);
}
