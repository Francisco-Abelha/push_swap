/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:15:17 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/08 14:45:53 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = ft_lstnew(argv[i]);
	stack_b = NULL;
	i++;
	while (argv[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
		i++;
	}
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	display_stacks(stack_a, stack_b);

	ft_printf("--------------\n");

	swap_b(&stack_b);
	push_a(&stack_a, &stack_b);
	
	display_stacks(stack_a, stack_b);

	ft_printf("-------------\n");
	
	rotate_a(&stack_a);
	
	display_stacks(stack_a, stack_b);

	ft_printf("-------------\n");
	
	reverse_rotate_a(&stack_a);
	
	display_stacks(stack_a, stack_b);
}
