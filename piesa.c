/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piesa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:21:42 by capetroa          #+#    #+#             */
/*   Updated: 2018/01/26 18:24:20 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_list		*elibereaza_lista(t_list *list)
{
	t_piesa	*piesa;
	t_list	*next;

	while (list)
	{
		piesa = (t_piesa*)list->content;
		next = list->next;
		elibereaza_piesa(piesa);
		ft_memdel((void**)&list);
		list = next;
	}
	return (NULL);
}

void		elibereaza_piesa(t_piesa *piesa)
{
	int y;

	y = 0;
	while (y < piesa->height)
	{
		ft_memdel((void**)(&(piesa->pos[y])));
		y++;
	}
	ft_memdel((void**)&piesa->pos);
	ft_memdel((void**)&piesa);
}

t_piesa		*creeaza_piesa(char **pos, int width, int height, char value)
{
	t_piesa	*piesa;

	piesa = ft_memalloc(sizeof(t_piesa));
	piesa->pos = pos;
	piesa->width = width;
	piesa->height = height;
	piesa->value = value;
	return (piesa);
}

t_punct		*creeaza_punct(int x, int y)
{
	t_punct *punct;

	punct = ft_memalloc(sizeof(ft_punct));
	punct->x = x;
	punct->y = y;
	return (punct);
}
