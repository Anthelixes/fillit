/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:25:55 by capetroa          #+#    #+#             */
/*   Updated: 2018/01/26 18:43:43 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_cmmp
{
	int		size;
	char	**array;
}				t_cmmp;

typedef struct	s_punct
{
	int		x;
	int		y;
}				t_punct;

typedef struct	s_piesa
{
	char	**pos;
	int		width;
	int		height;
	char	value;
}				t_piesa;

int		rezolva_cmmp(t_cmmp *cmmp, t_list *list);
int		radical(int n);
t_cmmp	*rezolva(t_list *list);
t_list	*elibereaza_spatiu(t_list *list);
void	elibereaza spatiu(t_piesa *piesa);
t_piesa	*creeaza_piesa(char **pos, int width, int height, char value);
t_punct *creeaza_punct(int x, int y);
void	elibereaza_cmmp(t_cmmp *cmmp);
void	afiseaza_cmmp(t_cmmp *cmmp);
t_cmmp	*creeaza_cmmp(int size);
int		verifica_loc(t_piesa *piesa, t_cmmp *cmmp, t_punct *punct, char c);
void	min_max(char *str, t_punct *min, t_punct *max);
t_piesa	*obtine_piesa(char *str, char value);
int		verifica_piesa(char *str);
int		verifica_componente(char *str, int count);
t_list	*citeste_piesa(int fisier);
#endif
