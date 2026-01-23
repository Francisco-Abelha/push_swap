/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:15:17 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/23 20:42:40 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*numbers;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	numbers = parse_args(argc, argv, &count);
	if (!numbers)
	{
		if (count == -1)  // Error occurred
			error_and_cleanup(&stack_a, &stack_b, NULL);
		return (0);  // Empty input, exit gracefully
	}
	if (count > 0)
	{
		stack_a = ft_lstnew(&numbers[0]);
		if (!stack_a)
			error_and_cleanup(&stack_a, &stack_b, numbers);
		i = 1;
		while (i < count)
		{
			ft_lstadd_back(&stack_a, ft_lstnew(&numbers[i]));
			i++;
		}
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free(numbers);
		return (0);
	}
	sort(&stack_a, &stack_b, numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(numbers);
	return (0);
}
