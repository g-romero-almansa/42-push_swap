/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:08 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/30 10:23:50 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_push_pa(t_stack *a, t_stack *b)
{
	a->max++;
	a->array[a->max] = b->array[b->max];
	b->array[b->max] = '\0';
	b->max--;
	write (1, "pa\n", 3);
}

void	ft_push_pb(t_stack *a, t_stack *b)
{
	b->max++;
	b->array[b->max] = a->array[a->max];
	a->array[a->max] = '\0';
	a->max--;
	write (1, "pb\n", 3);
}
