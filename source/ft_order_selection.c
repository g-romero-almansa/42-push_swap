/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:03:15 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/21 10:56:42 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_order_selection(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		ft_order_2(a);
	else if (argc == 4)
		ft_order_3(a);
	else if (argc == 5)
		ft_order_4(a, b);
	else if (argc == 6)
		ft_order_5(a, b);
	else if (argc > 6)
		if (ft_verify_order(a) == 1)
			ft_get_lis(a, b);
}

void	ft_order_2(t_stack *a)
{
	if (a->array[1] > a->array[0])
		ft_swap_sa(a);
}

void	ft_order_3(t_stack *a)
{
	if (a->array[2] > a->array[1] && a->array[2] < a->array[0]
		&& a->array[0] > a->array[1])
		ft_swap_sa(a);
	else if (a->array[2] > a->array[1] && a->array[2] > a->array[0]
		&& a->array[0] > a->array[1])
		ft_rotate_ra(a);
	else if (a->array[2] < a->array[1] && a->array[2] > a->array[0]
		&& a->array[0] < a->array[1])
		ft_reverse_rra(a);
	else if (a->array[2] > a->array[1] && a->array[2] > a->array[0]
		&& a->array[0] < a->array[1])
	{	
		ft_swap_sa(a);
		ft_reverse_rra(a);
	}
	else if (a->array[2] < a->array[1] && a->array[2] < a->array[0]
		&& a->array[0] < a->array[1])
	{
		ft_swap_sa(a);
		ft_rotate_ra(a);
	}
}

void	ft_order_4(t_stack *a, t_stack *b)
{
	if (ft_verify_order(a) == 1)
	{
		ft_find_smallest(a);
		if (a->index == 1)
		{
			ft_reverse_rra(a);
			ft_reverse_rra(a);
		}
		else if (a->index == 2)
			ft_rotate_ra(a);
		else if (a->index == 0)
			ft_reverse_rra(a);
		ft_push_pb(a, b);
		ft_order_3(a);
		ft_push_pa(a, b);
	}
}

void	ft_order_5(t_stack *a, t_stack *b)
{
	if (ft_verify_order(a) == 1)
	{
		ft_find_smallest(a);
		if (a->index == 0)
			ft_reverse_rra(a);
		else if (a->index == 1)
		{
			ft_reverse_rra(a);
			ft_reverse_rra(a);
		}
		else if (a->index == 2)
		{
			ft_rotate_ra(a);
			ft_rotate_ra(a);
		}
		else if (a->index == 3)
			ft_rotate_ra(a);
		ft_push_pb(a, b);
		ft_order_4(a, b);
		ft_push_pa(a, b);
	}
}
