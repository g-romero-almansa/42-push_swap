/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:58:10 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/23 12:25:46 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_moves(t_stack *a, t_stack *b)
{
	int		*mov_b;
	int		*mov_a;
	int		*mov_ab;
	int		i;
	//int		j;
	//int		k;

	i = b->max + 1;
	/*printf ("Stack A\n");
	j = a->max + 1;
	while (--j >= 0)
		printf ("%d         \n", a->array[j]);
	printf ("Stack B\n");
	k = b->max + 1;
	while (--k >= 0)
		printf ("%d\n", b->array[k]);*/
	while (--i >= 0)
	{
		mov_b = ft_moves_b(b);
		mov_a = ft_moves_a(a, b);
		mov_ab = ft_moves_ab(b, mov_a, mov_b);	
		ft_do_moves(a, b, mov_a, mov_b, ft_find_smallest_move(b->max, mov_ab));
		/*printf ("Stack A\n");
		j = a->max + 1;
		while (--j >= 0)
			printf ("%d         \n", a->array[j]);
		printf ("Stack B\n");
		k = b->max + 1; 
		while (--k >= 0)
			printf ("%d\n", b->array[k]);*/
	}
	while (ft_verify_order(a) == 1)
		ft_rotate_ra(a);
}

void	ft_do_moves(t_stack *a, t_stack *b, int *mov_a, int *mov_b, int index)
{
	while (mov_a[index] != 0 || mov_b[index] != 0)
	{
		if (mov_a[index] > 0 && mov_b[index] > 0)
		{
			mov_a[index] -= 1;
			mov_b[index] -= 1;
			ft_rotate_rr(a, b);
		}
		else if (mov_a[index] > 0 && mov_b[index] < 0)
		{
			mov_a[index] -= 1;
			mov_b[index] += 1;
			ft_rotate_ra(a);
			ft_reverse_rrb(b);
		}
		else if (mov_a[index] < 0 && mov_b[index] > 0)
		{
			mov_a[index] += 1;
			mov_b[index] -= 1;
			ft_reverse_rra(a);
			ft_rotate_rb(b);
		}
		else if (mov_a[index] < 0 && mov_b[index] < 0)
		{
			mov_a[index] += 1;
			mov_b[index] += 1;
			ft_reverse_rrr(a, b);
		}
		else if (mov_a[index] > 0)
		{
			mov_a[index] -= 1;
			ft_rotate_ra(a);
		}
		else if (mov_a[index] < 0)
		{
			mov_a[index] += 1;
			ft_reverse_rra(a);
		}
		else if (mov_b[index] > 0)
		{
			mov_b[index] -= 1;
			ft_rotate_rb(b);
		}
		else if (mov_b[index] < 0)
		{
			mov_b[index] += 1;
			ft_reverse_rrb(b);
		}
	}
	ft_push_pa(a, b);
}
int		*ft_moves_ab(t_stack *b, int *mov_a, int *mov_b)
{
	int		*mov_ab;
	int		i;

	mov_ab = (int *)malloc(b->max * sizeof(int));
	i = b->max + 1;
	while (--i >= 0)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0)
		{
			if (mov_a[i] >= mov_b[i])
				mov_ab[i] = mov_a[i];
			else
				mov_ab[i] = mov_b[i];
		}
		else if (mov_a[i] >= 0 && mov_b[i] < 0)
			mov_ab[i] = mov_a[i] + (mov_b[i] * -1);
		else if (mov_a[i] < 0 && mov_b[i] >= 0)
			mov_ab[i] = (mov_a[i] * -1) + mov_b[i];
		else if (mov_a[i] < 0 && mov_b[i] < 0)
		{	
			if (mov_a[i] >= mov_b[i])
				mov_ab[i] = mov_b[i] * -1;
			else
				mov_ab[i] = mov_a[i] * -1;
		}
	}
	return (mov_ab);
}

int		*ft_moves_b(t_stack *b)
{
	int		*mov_b;
	int		i;

	mov_b = (int *)malloc(b->max * sizeof(int));
	i = b->max;
	mov_b[i] = 0;
	mov_b[0] = -1;
	while (--i >= b->max / 2)
		mov_b[i] = mov_b[i + 1] + 1;
	i = 0;
	while (++i < b->max / 2)
		mov_b[i] = mov_b[i - 1] - 1;
	i = b->max + 1;
	return (mov_b);
}

int		*ft_moves_a(t_stack *a, t_stack *b)
{
	int		*mov_a;
	int		i;
	int		a_bigger;

	mov_a = (int *)malloc(b->max * sizeof(int));
	i = b->max + 1;
	a_bigger = ft_find_bigger(a);
	while (--i >= 0)
	{
		if (a_bigger < b->array[i])
			if (a->index >= a->max / 2)
				mov_a[i] = a->max - a->index + 1;
			else
				mov_a[i] = -(a->index + 1 - 1);
		else
		{
			mov_a[i] = ft_next_bigger(a, b->array[i]);	
			if (mov_a[i] >= a->max / 2)
				mov_a[i] = a->max - mov_a[i];
			else
				mov_a[i] = -(mov_a[i] + 1);
		}	
	}
	return (mov_a);
}
