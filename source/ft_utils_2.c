/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:04 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/09 12:50:51 by gromero-         ###   ########.fr       */
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
