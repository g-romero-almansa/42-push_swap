/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:38 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/11 10:52:30 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	ft_check_error(argv);
	a = malloc (sizeof(t_stack));
	b = malloc (sizeof(t_stack));
	a->array = (int *)malloc ((argc) * sizeof(int));
	b->array = (int *)malloc ((argc) * sizeof(int));
	if (!a->array || !b->array || !a || !b)
		return (0);
	a->max = argc - 2;
	b->max = -1;
	i = -1;
	while (argv[++i])
		a->array[i] = ft_atoi(argv[argc - 1 - i]);
	ft_order_selection(a, b, argc);
	free (a->array);
	free (b->array);
	free (a);
	free (b);
	return (0);
}
