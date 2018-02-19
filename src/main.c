/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:53:37 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:08:40 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

static int	get_square_size(void)
{
	int		square_size;
	float	float_nb;

	float_nb = ft_sqrt((float)(g_nb_tetrimino) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

void		free_tab(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int			main(int argc, char **argv)
{
	t_tetrimino *start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_usage();
		return (-1);
	}
	if ((tab = read_stdin(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if (check(tab) == 0)
	{
		ft_putendl("error");
		free_tab(tab, g_nb_tetrimino + 1);
		return (-1);
	}
	start = splittab(tab);
	free_tab(tab, g_nb_tetrimino + 1);
	puttab(solve(start, get_square_size(), NULL));
	return (0);
}
