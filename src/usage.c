/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capetroa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:55:18 by capetroa          #+#    #+#             */
/*   Updated: 2018/02/19 19:08:00 by capetroa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [File containing between 2 and 12 Tetriminos]");
	ft_putendl("        Note : If file contains more than 12 Tetriminos,");
	ft_putendl("               The program will run slowly.");
}
