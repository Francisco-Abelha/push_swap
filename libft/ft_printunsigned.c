/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:04:05 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/11 16:29:22 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	num_len(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_u_putnbr(unsigned int n)
{
	if (n >= 10)
		ft_u_putnbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_printunsigned(unsigned int num)
{
	ft_u_putnbr(num);
	return (num_len(num));
}
