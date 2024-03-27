/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:37:47 by mbankhar          #+#    #+#             */
/*   Updated: 2024/03/25 10:10:39 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	print_digitptr(unsigned long n, unsigned long base);

int	print_ptr(void *ptr)
{
	unsigned long	ptr_value;
	int				count;

	ptr_value = (unsigned long)ptr;
	count = 0;
	if (ptr_value == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	count += print_digitptr(ptr_value, 16);
	return (count);
}

int	print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit((long)va_arg(args, int), 10));
	else if (specifier == 'x')
		return (print_digit((long)va_arg(args, unsigned int), 16));
	else if (specifier == 'X')
		return (print_digitup((long)va_arg(args, unsigned int), 16));
	else if (specifier == 'u')
		return (print_digit((long)va_arg(args, unsigned int), 10));
	else if (specifier == 'p')
		return (print_ptr(va_arg(args, void *)));
	else
		return (write(1, &specifier, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count ;
	int			temp;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp = print_format(*(++format), ap);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			count += 1;
		}
		++format;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// int	count;
// int count2;

// char	a = 'a';
// char	b[10] = "Is it?";
// 	printf("%%c\n");
// 	count = ft_printf("%%c");
// }
