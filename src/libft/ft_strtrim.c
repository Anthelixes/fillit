/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:09:57 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 15:10:01 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = len - i;
	if (!(str = ft_strsub((char *)s, i, len)))
		return (NULL);
	str[len] = 0;
	return (str);
}
