/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:12:59 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/01/23 19:38:14 by fgoncal2         ###   ########.fr       */
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
int		parse_int(const char *str, int *error);
int		check_duplicates(int *arr, int count);
int		*parse_args(int argc, char **argv, int *count_out);

//sort
int		is_sorted(t_list *stack_a);
void	sort(t_list **stack_a, t_list **stack_b, int *numbers);
void	sort_3(t_list **stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b, int *numbers);

//util
void	free_stack(t_list **stack);
void	error_and_cleanup(t_list **stack_a, t_list **stack_b, int *numbers);

#endif
