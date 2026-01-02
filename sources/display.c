/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:37:11 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/02 19:51:16 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stacks(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a && !stack_b)
		return ;
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			ft_printf("  [%s]", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  [ ]");
		if (stack_b != NULL)
		{
			ft_printf("  [%s]\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("  [ ]\n");
	}
}