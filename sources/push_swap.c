/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:15:17 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/15 20:37:42 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*numbers;

	numbers = parse_args(argc, argv);
	if (!numbers)
		return (1);
	stack_a = ft_lstnew(&numbers[0]);
	stack_b = NULL;
	i = 1;
	while (i < argc - 1)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(&numbers[i]));
		i++;
	}
	if (is_sorted(stack_a))
		return 0;
	sort(&stack_a, &stack_b);
	display_stacks(stack_a, stack_b);

}
