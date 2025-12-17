/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:46:36 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/16 17:12:28 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// funcao auxilar para calcular a media
static long	get_avg(t_node *stack)
{
	long	sum;
	int		size;

	if (!stack)
		return (0);
	sum = 0;
	size = get_size(stack);
	while (stack)
	{
		sum += stack->val;
		stack = stack->next;
	}
	return (sum / size);
}

void	sort_tiny(t_node **a)
{
	t_node	*high;

	high = find_max(*a);
	if (*a == high)
		ra(a, 1);
	else if ((*a)->next == high)
		rra(a, 1);
	if ((*a)->val > (*a)->next->val)
		sa(a, 1);
}

static void	move_top(t_node **s, t_node *top, char name)
{
	while (*s != top)
	{
		if (name == 'a')
		{
			if (top->above_med)
				ra(s, 1);
			else
				rra(s, 1);
		}
		else
		{
			if (top->above_med)
				rb(s, 1);
			else
				rrb(s, 1);
		}
	}
}

static void	push_back(t_node **a, t_node **b)
{
	t_node	*best;

	best = *b;
	while (best && !best->best_match)
		best = best->next;
	if (best->above_med && best->target->above_med)
		while (*b != best && *a != best->target)
			rr(a, b, 1);
	else if (!best->above_med && !best->target->above_med)
		while (*b != best && *a != best->target)
			rrr(a, b, 1);
	update_nodes(*a, *b);
	move_top(b, best, 'b');
	move_top(a, best->target, 'a');
	pa(a, b, 1);
}

void	solve_complex(t_node **a, t_node **b)
{
	int		len;
	long	avg;

	len = get_size(*a);
	while (len-- > 3 && !check_sorted(*a))
	{
		pb(b, a, 1);
		avg = get_avg(*a);
		if ((*b)->val < avg && get_size(*b) > 1)
			rb(b, 1);
	}
	sort_tiny(a);
	while (*b)
	{
		update_nodes(*a, *b);
		push_back(a, b);
	}
	update_nodes(*a, *b);
	move_top(a, find_min(*a), 'a');
}
