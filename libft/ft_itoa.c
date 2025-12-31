/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:05:55 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/04 12:06:46 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*fill_number(char *ret, unsigned int nbr, size_t len, size_t is_neg)
{
	ret[len] = '\0';
	while (len-- > is_neg)
	{
		ret[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (is_neg)
		ret[0] = '-';
	return (ret);
}

static char	*handle_int_min(void)
{
	char	*ret;

	ret = malloc(12);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, "-2147483648", 12);
	return (ret);
}

char	*ft_itoa(int n)
{
	size_t			len;
	size_t			is_negative;
	char			*ret;
	unsigned int	nbr;

	is_negative = 0;
	if (n == -2147483648)
		return (handle_int_min());
	if (n < 0)
	{
		is_negative = 1;
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	len = num_len(nbr);
	if (is_negative)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	return (fill_number(ret, nbr, len, is_negative));
}
