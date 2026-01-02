/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:37:11 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/02 23:11:03 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	display_a(int size_a, int row, int max, t_list *stack_a)
{
	int 	i;
	t_list	*tmp;

	i = 0;
	if (row < max - size_a)
		ft_printf("  [ ]");
	else
	{
		tmp = stack_a;
		while (i++ < row - (max - size_a))
			tmp = tmp->next;
		ft_printf("  [%s]", (char *)tmp->content);
	}
}

static void	display_b(int size_b, int row, int max, t_list *stack_b)
{
	int 	i;
	t_list	*tmp;

	i = 0;
	if (row < max - size_b)
		ft_printf("  [ ]\n");
	else
	{
		tmp = stack_b;
		while (i++ < row - (max - size_b))
			tmp = tmp->next;
		ft_printf("  [%s]\n", (char *)tmp->content);
	}
}

void	display_stacks(t_list *stack_a, t_list *stack_b)
{
	int		size_a;
	int		size_b;
	int		max;
	int		row;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	max = (size_a > size_b) ? size_a : size_b;
	row = 0;
	while (row < max)
	{
		display_a(size_a, row, max, stack_a);
		display_b(size_b, row, max, stack_b);
		row++;
	}
}
