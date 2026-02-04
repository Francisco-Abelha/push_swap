/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:12:59 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/02/04 15:38:32 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <errno.h>

//operations
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
void	error_exit(t_list **a, t_list **b);
void	free_stack(t_list **stack);
void	free_split(char **split);

//parse
int		*parse_arguments(int argc, char **argv, t_list **stack_a);

//sort
int		is_sorted(t_list *stack_a);
void	sort(t_list **stack_a, t_list **stack_b, int *values);
void	sort_3(t_list **stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b, int *values);
void	assign_sorted_indices(t_list **stack_a, int *values, unsigned int size);
void	bit_pass(t_list **a, t_list **b, unsigned int size, unsigned int bit);

//utils
int		ft_atoi_checked(const char *str);
char	**safe_split(char *arg);
void	append_split(char **tokens, char **split, int *k);
int		count_tokens(int argc, char **argv);

//sort utils
void	bring_min_to_top(t_list **stack_a);
int		find_index(t_list *a, int target);
int		find_min(t_list *a);
int		bit_length(unsigned int value);

#endif
