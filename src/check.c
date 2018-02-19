/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:53:22 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:08:24 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static	int		check_char(char *s)
{
	int i;
	int hash;
	int point;
	int endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 4)
		return (0);
	return (1);
}

static	int		check_line(char *s)
{
	int x;
	int y;
	int add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

static	int		check_shape(char *s)
{
	int height;
	int width;

	height = get_height(s);
	width = get_width(s);
	if (is_alone(s) == 0)
		return (0);
	if (check_void_int(s) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int				check(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetrimino)
	{
		if (check_char(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		if (check_shape(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int				first_test(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
			if (buf[x + 1] != '\n' && buf[x + 1] != '\0')
				return (0);
			if (buf[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
