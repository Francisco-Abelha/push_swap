/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:04:30 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/08 15:00:48 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*old_head;
	t_list	*new_head;

	if (ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		old_head = *stack;
		new_head = (*stack)->next;
		*stack = new_head;
		last->next = old_head;
		old_head->next = NULL;
	}
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
