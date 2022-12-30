/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:14:12 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/30 10:28:06 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_reverse_rra(t_stack *a)
{
	int		acum;
	int		acum2;
	int		i;

	acum2 = a->array[0];
	i = -1;
	while (a->array[++i])
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
	write (1, "rra\n", 4);
}

void	ft_reverse_rrb(t_stack *b)
{
	int		acum;
	int		acum2;
	int		i;

	acum2 = b->array[0];
	i = -1;
	while (b->array[++i])
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
	write (1, "rrb\n", 4);
}

void	ft_reverse_rrr(t_stack *a, t_stack *b)
{
	int		acum;
	int		acum2;
	int		i;

	acum2 = a->array[0];
	i = -1;
	while (a->array[++i])
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
	acum2 = b->array[0];
	i = -1;
	while (b->array[++i])
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
	write (1, "rrr\n", 4);
}
