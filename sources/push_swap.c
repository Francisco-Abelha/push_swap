/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:15:17 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/11 18:44:06 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*values;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	values = parse_arguments(argc, argv, &stack_a);
	if (!values)
		error_exit(&stack_a, &stack_b);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b, values);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(values);
	return (0);
}
