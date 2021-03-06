/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:54:26 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:09:00 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		get_width(char *s)
{
	int i;
	int width;
	int line_void;

	i = 0;
	width = 0;
	line_void = 0;
	while (i < 4)
	{
		if (s[i] == '#' || s[i + 5] == '#' || s[i + 10] == '#' ||\
				s[i + 15] == '#')
		{
			width++;
			if (line_void > 0)
				return (0);
		}
		else if (width > 0)
			line_void++;
		i++;
	}
	return (width);
}

int		get_height(char *s)
{
	int i;
	int height;
	int line_void;

	i = 0;
	height = 0;
	line_void = 0;
	while (i < 19)
	{
		if (s[i] == '#' || s[i + 1] == '#' || s[i + 2] == '#' ||\
				s[i + 3] == '#')
		{
			height++;
			if (line_void > 0)
				return (0);
		}
		else if (height > 0)
			line_void++;
		i = i + 5;
	}
	return (height);
}

int		check_void_int(char *s)
{
	int i;
	int h;
	int bug;

	bug = 0;
	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			h++;
		if (h == 2 && s[i] == '#')
		{
			while (s[i + 1 + bug] != '#' && s[i + bug] != '\0')
				bug++;
			if (bug > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int		is_alone(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' ||\
					s[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
