/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:33:20 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/09 12:59:34 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_rotate_ra(t_stack *a, int wr)
{
	int		acum;
	int		acum2;
	int		max;

	acum2 = a->array[a->max];
	max = a->max;
	while (a->array[max])
	{
		if (max == 0)
			a->array[0] = acum2;
		else
		{
			acum = a->array[max];
			a->array[max] = a->array[max - 1];
			a->array[max - 1] = acum;
		}
		max--;
	}
	if (wr == 1)
		write (1, "ra\n", 3);
}

void	ft_rotate_rb(t_stack *b, int wr)
{
	int		acum;
	int		acum2;
	int		max;

	acum2 = b->array[b->max];
	max = b->max;
	while (b->array[max])
	{
		if (max == 0)
		{
			b->array[0] = acum2;
			max --;
		}
		else
		{
			acum = b->array[max];
			b->array[max] = b->array[max - 1];
			b->array[max - 1] = acum;
			max--;
		}
	}
	if (wr != 2)
		write (1, "rb\n", 3);
}

void	ft_rotate_rr(t_stack *a, t_stack *b)
{
	ft_rotate_ra(a, 2);
	ft_rotate_rb(b, 2);
	write (1, "rr\n", 3);
}
