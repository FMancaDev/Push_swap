/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:33:45 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 15:23:34 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rev_rotate(t_node **lst)
{
	t_node	*last;
	t_node	*head;

	if (!*lst || !(*lst)->next)
		return ;
	head = *lst;
	last = get_last(head);
	last->prev->next = NULL;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	*lst = last;
}

void	rra(t_node **a, int p)
{
	rev_rotate(a);
	if (p)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int p)
{
	rev_rotate(b);
	if (p)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int p)
{
	rev_rotate(a);
	rev_rotate(b);
	if (p)
		write(1, "rrr\n", 4);
}
