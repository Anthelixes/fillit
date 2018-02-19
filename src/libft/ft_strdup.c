/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:30:25 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:30:27 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size_s;
	int		i;
	char	*ret;

	i = -1;
	size_s = ft_strlen(s);
	if (!(ret = (char *)malloc((size_s + 1) * sizeof(char))))
		return (NULL);
	while (s[++i] != '\0')
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
