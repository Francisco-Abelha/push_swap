/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:12:59 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/19 02:16:45 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <errno.h>

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);

//error
void	print_error_and_exit(void);
int		parse_int(const char *str);
void	check_duplicates(int *arr, int count);
int		*parse_args(int argc, char **argv, int *count_out);

//sort
int		is_sorted(t_list *stack_a);
void	sort(t_list **stack_a, t_list **stack_b, int *numbers);
void	sort_3(t_list **stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b, int *numbers);

//display
void	display_stacks(t_list *stack_a, t_list *stack_b);

#endif
