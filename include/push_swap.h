/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:42:14 by gromero-          #+#    #+#             */
/*   Updated: 2023/01/09 13:01:28 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int		*array;
	int		max;
	int		index;
}	t_stack;

void	ft_order_selection(t_stack *a, t_stack *b, int argc);

void	ft_find_smallest(t_stack *a);

int		ft_find_smallest_move(int i, int *mov);

int		ft_find_bigger(t_stack *a);

void	ft_index_smallest(t_stack *a, int i);

int		ft_index_max(int *lis, t_stack *a);

int		ft_next_bigger(t_stack *a, int num_b);

int		ft_verify_order(t_stack *a);

void	ft_order_2(t_stack *a);

void	ft_order_3(t_stack *a);

void	ft_order_4(t_stack *a, t_stack *b);

void	ft_order_5(t_stack *a, t_stack *b);

void	ft_get_lis(t_stack *a, t_stack *b);

void	ft_get_seq(int *lis, int max_lis, t_stack *a, t_stack *b);

void	ft_lis_to_b(t_stack *a, t_stack *b, int *seq, int max_seq);

void	ft_moves(t_stack *a, t_stack *b);

int		*ft_moves_b(t_stack *b);

int		*ft_moves_a(t_stack *a, t_stack *b);

int		*ft_moves_ab(t_stack *b, int *mov_a, int *mov_b);

void	ft_do_moves(t_stack *a, t_stack *b, int *mov_a, int *mov_b);

void	ft_swap_sa(t_stack *a);

void	ft_swap_sb(t_stack *b);

void	ft_swap_ss(t_stack *a, t_stack *b);

void	ft_push_pa(t_stack *a, t_stack *b);

void	ft_push_pb(t_stack *a, t_stack *b);

void	ft_rotate_ra(t_stack *a, int wr);

void	ft_rotate_rb(t_stack *b, int wr);

void	ft_rotate_rr(t_stack *a, t_stack *b);

void	ft_reverse_rra(t_stack *a, int wr);

void	ft_reverse_rrb(t_stack *b, int wr);

void	ft_reverse_rrr(t_stack *a, t_stack *b);

void	ft_check_error(char **argv);

void	ft_error(int num);

#endif
