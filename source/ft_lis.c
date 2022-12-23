/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:12:22 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/21 13:19:32 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_get_seq(int *lis, int max_lis, t_stack *a, t_stack *b)
{
	int	*seq;
	int	i;
	int	max_seq;

	max_seq = max_lis - 1;
	seq = (int *)malloc(max_lis * sizeof(int));
	i = -1;
	while (++i <= a->max && max_lis > 0)
	{
		if (lis[i] == max_lis)
		{
			seq[max_lis - 1] = a->array[i];
			max_lis--;
		}
	}
	ft_lis_to_b(a, b, seq, max_seq);
}

void	ft_get_lis(t_stack *a, t_stack *b)
{
	int		*lis;
	int		i;
	int		j;

	lis = (int *)malloc(a->max * sizeof(int));
	i = a->max;
	while (--i >= 0)
	{
		lis[a->max] = 1;
		lis[i] = 1;
		j = a->max + 1;
		while (--j > i)
			if (a->array[i] > a->array[j] && lis[i] < (lis[j] + 1))
				lis[i] = lis[j] + 1;
	}
	ft_get_seq(lis, ft_index_max(lis, a), a, b);
}

void	ft_lis_to_b(t_stack *a, t_stack *b, int *seq, int max_seq)
{
	int	i;
	int	j;

	i = 0;
	j = a->max;
	while (j >= 0)
	{
		if (seq[i] == a->array[a->max] && i <= max_seq)
		{
			ft_rotate_ra(a);
			i++;
		}
		else
			ft_push_pb(a, b);
		j--;
	}
	ft_moves(a, b);
}
