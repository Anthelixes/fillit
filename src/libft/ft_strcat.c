/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:30:15 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:30:16 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		size;
	int		cpt;

	cpt = 0;
	size = ft_strlen(s1);
	while (s2[cpt])
		s1[size++] = s2[cpt++];
	s1[size] = '\0';
	return (s1);
}
