/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:02:44 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/09 12:51:05 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_find_smallest(t_stack *a)
{
	int		i;
	int		smallest;

	i = 0;
	smallest = a->array[0];
	a->index = 0;
	while (++i <= a->max)
	{
		if (a->array[i] < smallest)
		{
			smallest = a->array[i];
			a->index = i;
		}
	}
}

int	ft_find_smallest_move(int i, int *mov)
{
	int		acum;
	int		j;

	acum = mov[i];
	j = i;
	while (--i >= 0)
	{	
		if (mov[i] < acum)
		{
			acum = mov[i];
			j = i;
		}
	}
	return (j);
}

int	ft_find_bigger(t_stack *a)
{
	int		i;
	int		bigger;

	i = 0;
	bigger = a->array[0];
	a->index = 0;
	while (++i <= a->max)
	{
		if (a->array[i] > bigger)
		{	
			bigger = a->array[i];
			a->index = i;
		}
	}
	return (bigger);
}

void	ft_index_smallest(t_stack *a, int i)
{
	int	smallest;

	smallest = a->array[i];
	while (i <= a->max)
	{
		if (a->array[i] < smallest)
		{
			smallest = a->array[i];
			a->index = i;
		}
		i++;
	}
}

int	ft_index_max(int *lis, t_stack *a)
{
	int	i;
	int	acum;

	acum = lis[0];
	i = 0;
	while (++i <= a->max)
	{
		if (acum < lis[i])
			acum = lis[i];
	}
	return (acum);
}
