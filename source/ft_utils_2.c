/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:04 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/10 11:24:55 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_next_bigger(t_stack *a, int num_b)
{
	int		i;
	int		acum;
	int		index;

	i = a->max + 1;
	acum = ft_find_bigger(a);
	while (--i >= 0)
	{
		if (a->array[i] <= acum && num_b < a->array[i])
		{
			acum = a->array[i];
			index = i;
		}
	}
	return (index);
}

int	ft_verify_order(t_stack *a)
{
	int		i;

	i = -1;
	while (++i < a->max)
		if (a->array[i] < a->array[i + 1])
			return (1);
	return (0);
}

void	ft_move_sup(t_stack *a, t_stack *b, int *mov_a, int *mov_b)
{
	int		index;

	index = ft_find_smallest_move(b->max, ft_moves_ab(b, mov_a, mov_b));
	if (mov_a[index] > 0 && mov_b[index] < 0)
	{
		ft_rotate_ra(a, 1);
		ft_reverse_rrb(b, 1);
	}
	else if (mov_a[index] < 0 && mov_b[index] > 0)
	{
		ft_reverse_rra(a, 1);
		ft_rotate_rb(b, 1);
	}
	else if (mov_a[index] < 0 && mov_b[index] < 0)
		ft_reverse_rrr(a, b);
	else if (mov_a[index] > 0)
		ft_rotate_ra(a, 1);
	else if (mov_a[index] < 0)
		ft_reverse_rra(a, 1);
	else if (mov_b[index] > 0)
		ft_rotate_rb(b, 1);
	else if (mov_b[index] < 0)
		ft_reverse_rrb(b, 1);
}
