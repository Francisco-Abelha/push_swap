/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:19:28 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/10 21:01:12 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_specifiers(va_list *args, const char format)
{
	int	chars_printed;

	chars_printed = 0;
	if (format == 'c')
		chars_printed += ft_printchar(va_arg(*args, int));
	else if (format == 's')
		chars_printed += ft_printstr(va_arg(*args, char *));
	else if (format == 'i' || format == 'd')
		chars_printed += ft_printnum(va_arg(*args, int));
	else if (format == 'u')
		chars_printed += ft_printunsigned(va_arg(*args, unsigned int));
	else if (format == 'X' || format == 'x')
		chars_printed += ft_printhex(va_arg(*args, unsigned int), format);
	else if (format == 'p')
		chars_printed += ft_printptr(va_arg(*args, unsigned long long));
	else if (format == '%')
		chars_printed += ft_printchar('%');
	return (chars_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	chars_printed = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				chars_printed += f_specifiers(&args, *format);
		}
		else
			chars_printed += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (chars_printed);
}
