/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:53:04 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:06:51 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static char		**arrange_up(int i_min, char **tab)
{
	int i;

	i = 0;
	while (i + i_min < 4)
	{
		tab[i] = tab[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tab[i] = "....\0";
		i++;
	}
	return (tab);
}

static char		**arrange_left(int j_min, char **tab)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + j_min] != '\0')
		{
			tab[i][j] = tab[i][j + j_min];
			j++;
		}
		tmp = j_min;
		while (tmp > 0 && tmp > 0)
		{
			tab[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static int		get_y_min(char **tab)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

static int		get_x_min(char **tab)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

t_tetrimino		*arrange(t_tetrimino *start)
{
	t_tetrimino *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = arrange_left(get_x_min(tmp->tetrimino),\
				tmp->tetrimino);
		tmp->tetrimino = arrange_up(get_y_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}
