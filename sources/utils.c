/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:28:38 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/23 19:30:15 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*next;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	*stack = NULL;
}

void	error_and_cleanup(t_list **stack_a, t_list **stack_b, int *numbers)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	if (numbers)
		free(numbers);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
