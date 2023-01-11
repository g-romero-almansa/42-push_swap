/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:14:12 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/11 11:23:39 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_reverse_rra(t_stack *a, int wr)
{
	int		acum;
	int		acum2;
	int		i;

	acum2 = a->array[0];
	i = -1;
	while (++i <= a->max)
	{
		if (i == a->max)
			a->array[a->max] = acum2;
		else
		{
			acum = a->array[i];
			a->array[i] = a->array[i + 1];
			a->array[i + 1] = acum;
		}
	}
	if (wr != 2)
		write (1, "rra\n", 4);
}

void	ft_reverse_rrb(t_stack *b, int wr)
{
	int		acum;
	int		acum2;
	int		i;

	acum2 = b->array[0];
	i = -1;
	while (++i <= b->max)
	{
		if (i == b->max)
			b->array[b->max] = acum2;
		else
		{
			acum = b->array[i];
			b->array[i] = b->array[i + 1];
			b->array[i + 1] = acum;
		}
	}
	if (wr != 2)
		write (1, "rrb\n", 4);
}

void	ft_reverse_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rra(a, 2);
	ft_reverse_rrb(b, 2);
	write (1, "rrr\n", 4);
}
