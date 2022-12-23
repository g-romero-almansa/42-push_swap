/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:38 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/23 12:25:16 by gromero-         ###   ########.fr       */
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
	a->array = malloc ((argc - 1) * sizeof(int));
	b->array = malloc ((argc - 1) * sizeof(int));
	if (!a->array || !b->array)
		return (0);
	a->max = argc - 2;
	b->max = -1;
	i = -1;
	while (argv[++i])
		a->array[i] = ft_atoi(argv[argc - 1 - i]);
	ft_order_selection(a, b, argc);
	/*printf ("Stack A\n");
	while (a->max >= 0)
	{
		printf ("%d\n", a->array[a->max]);
		a->max--;
	}
	printf ("Stack B\n");
	while (b->max >= 0)
	{	
		printf("%d\n", b->array[b->max]);
		b->max--;
	}*/
	return (0);
}
