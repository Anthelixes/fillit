/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:55:03 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:09:21 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			get_nb_tetrimino(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

t_tetrimino	*newtetri(char **tetrimino, int num)
{
	t_tetrimino *new;

	new = NULL;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tetrimino;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char		**create_tab(char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i++] = '.';
		}
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
