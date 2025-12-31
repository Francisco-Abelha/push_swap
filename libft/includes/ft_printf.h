/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:20:15 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/12/31 00:37:50 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <stdint.h>

int	ft_printf(const char *format, ...);

//utils
int	ft_printstr(char *str);
int	ft_printchar(int c);
int	ft_printnum(int num);
int	ft_printunsigned(unsigned int num);
int	ft_printhex(unsigned int num, const char format);
int	ft_printptr(unsigned long long num);

#endif
