/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:30:16 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/06 16:00:25 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>


typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// stack and stack utils
t_stack		*find_last_node(t_stack *head);
void		append_node(t_stack **stack, int n);
void		init_stack_a(t_stack **a, char **argv);

// utils
long	ft_atol(const char *str);

// error
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

#endif
