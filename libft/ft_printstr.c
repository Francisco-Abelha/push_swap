/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:46:24 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/10 02:55:06 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	chars_printed;

	chars_printed = 0;
	if (!str)
		return (ft_putstr_fd("(null)", 1), 6);
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		chars_printed++;
		str++;
	}
	return (chars_printed);
}
