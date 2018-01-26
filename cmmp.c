/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:56:44 by capetroa          #+#    #+#             */
/*   Updated: 2018/01/26 18:40:25 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		elibereaza_cmmp(t_cmmp *cmmp)
{
	int i;

	i = 0;
	while (i < cmmp->size)
	{
		ft_memdel((void**)&(cmmp->array[i]));
		i++;
	}
	ft_memdel((void**)&(cmmp->array));
	ft_memdel((void**)&cmmp);
}

void		afiseaza_cmmp(t_cmmp *cmmp)
{
	int i;

	i = 0;
	while (i < cmmp->size)
	{
		ft_putstr(cmmp->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_cmmp		*creeaza_cmmp(int size)
{
	t_cmmp	*cmmp;
	int		i;
	int		j;

	cmmp = (t_cmmp *)ft_memalloc(sizeof(t_cmmp));
	cmmp->size = size;
	cmmp->array = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		cmmp->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			cmmp->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (cmmp);
}

int			verifica_loc(t_piesa *piesa, t_cmmp *cmmp, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < piesa->width)
	{
		j = 0;
		while (j < piesa->height)
		{
			if (piesa->pos[j][i] == '#' && cmmp->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	pune_piesa(piesa, cmmp, punct_nou(x, y), piesa->value);
	return (1);
}

void		pune_piesa(t_piesa *piesa, t_cmmp *cmmp, t_punct *punct, char c)
{
	int i;
	int j;

	i = 0;
	while (i < piesa->width)
	{
		j = 0;
		while (j < piesa->height)
		{
			if (piesa->pos[j][i] == '#')
				cmmp->array[punct->x + j][punct->y + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&punct);
}
