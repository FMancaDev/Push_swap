/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:21:52 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/13 15:23:12 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_node **lst)
{
	t_node	*last;
	t_node	*head;

	if (!*lst || !(*lst)->next)
		return ;
	head = *lst;
	last = get_last(head);
	*lst = head->next;
	(*lst)->prev = NULL;
	last->next = head;
	head->prev = last;
	head->next = NULL;
}

void	ra(t_node **a, int p)
{
	rotate(a);
	if (p)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int p)
{
	rotate(b);
	if (p)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int p)
{
	rotate(a);
	rotate(b);
	if (p)
		write(1, "rr\n", 3);
}
