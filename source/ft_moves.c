/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:58:10 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/11 10:55:42 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_moves(t_stack *a, t_stack *b)
{
	int		i;

	i = b->max + 1;
	while (--i >= 0)
		ft_do_moves(a, b, ft_moves_a(a, b), ft_moves_b(b));
	ft_find_smallest(a);
	while (ft_verify_order(a) == 1)
	{
		if (a->index >= (a->max / 2))
			ft_rotate_ra(a, 1);
		else
			ft_reverse_rra(a, 1);
	}
}

void	ft_do_moves(t_stack *a, t_stack *b, int *mov_a, int *mov_b)
{
	int		index;

	index = ft_find_smallest_move(b->max, ft_moves_ab(b, mov_a, mov_b));
	while (mov_a[index] != 0 || mov_b[index] != 0)
	{
		if (mov_a[index] > 0 && mov_b[index] > 0)
			ft_rotate_rr(a, b);
		else
			ft_move_sup(a, b, mov_a, mov_b);
		if (mov_a[index] > 0)
			mov_a[index] -= 1;
		else if (mov_a[index] < 0)
			mov_a[index] += 1;
		if (mov_b[index] > 0)
			mov_b[index] -= 1;
		else if (mov_b[index] < 0)
			mov_b[index] += 1;
	}
	ft_push_pa(a, b);
	free (mov_a);
	free (mov_b);
}

int	*ft_moves_ab(t_stack *b, int *mov_a, int *mov_b)
{
	int		*mov_ab;
	int		i;

	mov_ab = (int *)malloc((b->max + 1) * sizeof(int));
	i = -1;
	while (++i <= b->max)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0)
			if (mov_a[i] > mov_b[i])
				mov_ab[i] = mov_a[i];
		else
			mov_ab[i] = mov_b[i];
		else if (mov_a[i] >= 0 && mov_b[i] < 0)
			mov_ab[i] = mov_a[i] + (mov_b[i] * -1);
		else if (mov_a[i] < 0 && mov_b[i] >= 0)
			mov_ab[i] = (mov_a[i] * -1) + mov_b[i];
		else if (mov_a[i] < 0 && mov_b[i] < 0)
		{	
			if (mov_a[i] > mov_b[i])
				mov_ab[i] = mov_b[i] * -1;
			else
				mov_ab[i] = mov_a[i] * -1;
		}
	}
	return (mov_ab);
}

int	*ft_moves_b(t_stack *b)
{
	int		*mov_b;
	int		i;

	mov_b = (int *)malloc((b->max + 1) * sizeof(int));
	i = b->max + 1;
	while (--i >= 0)
	{
		if (i >= b->max / 2)
			mov_b[i] = b->max - i;
		else
			mov_b[i] = -(i + 1);
	}	
	return (mov_b);
}

int	*ft_moves_a(t_stack *a, t_stack *b)
{
	int		*mov_a;
	int		i;
	int		a_bigger;
	int		index;

	mov_a = (int *)malloc((b->max + 1) * sizeof(int));
	i = b->max + 1;
	a_bigger = ft_find_bigger(a);
	while (--i >= 0)
	{
		if (a_bigger < b->array[i])
			if (a->index >= a->max / 2)
				mov_a[i] = a->max - a->index + 1;
		else
			mov_a[i] = -(a->index);
		else
		{
			index = ft_next_bigger(a, b->array[i]);
			if (index >= a->max / 2)
				mov_a[i] = a->max - index;
			else
				mov_a[i] = -(index + 1);
		}	
	}
	return (mov_a);
}
