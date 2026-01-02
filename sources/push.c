/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:55:00 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/02 23:14:14 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = *stack_b;
	(*stack_b) = (*stack_b)->next;
	node->next = NULL;
	ft_lstadd_front(stack_a, node);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = *stack_a;
	(*stack_a) = (*stack_a)->next;
	node->next = NULL;
	ft_lstadd_front(stack_b, node);
}
