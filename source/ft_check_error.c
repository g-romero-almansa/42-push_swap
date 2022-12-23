/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:34:14 by gromero-          #+#    #+#             */
/*   Updated: 2022/12/15 11:13:13 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_check_error(char **argv)
{
	int		i;
	int		j;
	int		acum;

	i = 0;
	while (argv[++i])
	{
		j = i;
		acum = ft_atoi(argv[i]);
		while (argv[++j])
			if (ft_atoi(argv[j]) == acum)
				ft_error(1);
		j = 0;
		while (argv[i][++j])
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][0] != '-')
				ft_error(1);
	}
}

void	ft_error(int num)
{
	if (num == 1)
	{
		write (1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}
