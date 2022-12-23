/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:12:29 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/13 12:02:11 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_swap_sa(t_stack *a)
{
	int	acum;

	acum = a->array[a->max];
	a->array[a->max] = a->array[a->max - 1];
	a->array[a->max - 1] = acum;
	write (1, "sa\n", 3);
}

void	ft_swap_sb(t_stack *b)
{
	int	acum;

	acum = b->array[b->max];
	b->array[b->max] = b->array[b->max - 1];
	b->array[b->max - 1] = acum;
	write (1, "sb\n", 3);
}

void	ft_swap_ss(t_stack *a, t_stack *b)
{
	int	acum;

	acum = a->array[a->max];
	a->array[a->max] = a->array[a->max - 1];
	a->array[a->max - 1] = acum;
	acum = b->array[b->max];
	b->array[b->max] = b->array[b->max - 1];
	b->array[b->max - 1] = acum;
	write (1, "ss\n", 3);
}
