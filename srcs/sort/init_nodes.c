/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:58:44 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/16 19:12:07 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_pos(t_node *n)
{
	int	i;
	int	mid;

	i = 0;
	if (!n)
		return ;
	mid = get_size(n) / 2;
	while (n)
	{
		n->pos = i;
		if (i <= mid)
			n->above_med = 1;
		else
			n->above_med = 0;
		n = n->next;
		i++;
	}
}

static void	set_target(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*best_t;
	long	match_val;

	while (b)
	{
		match_val = LONG_MAX;
		curr_a = a;
		best_t = NULL;
		while (curr_a)
		{
			if (curr_a->val > b->val && curr_a->val < match_val)
			{
				match_val = curr_a->val;
				best_t = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match_val == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = best_t;
		b = b->next;
	}
}

// calcula o custo do movimento
static void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = get_size(a);
	len_b = get_size(b);
	while (b)
	{
		b->price = b->pos;
		if (!b->above_med)
			b->price = len_b - b->pos;
		if (b->target->above_med)
			b->price += b->target->pos;
		else
			b->price += len_a - b->target->pos;
		b = b->next;
	}
}

// atualiza os nodes e avanca
void	update_nodes(t_node *a, t_node *b)
{
	long	best_price;
	t_node	*best_node;

	set_pos(a);
	set_pos(b);
	set_target(a, b);
	set_price(a, b);
	best_price = LONG_MAX;
	best_node = NULL;
	while (b)
	{
		if (b->price < best_price)
		{
			best_price = b->price;
			best_node = b;
		}
		b = b->next;
	}
	if (best_node)
		best_node->best_match = 1;
}
