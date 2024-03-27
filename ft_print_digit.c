/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:15:35 by mbankhar          #+#    #+#             */
/*   Updated: 2024/03/25 09:51:14 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;
	int		temp;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		if (count == -1)
			return (-1);
		temp = print_digit(n % base, base);
		if (temp == -1)
			return (-1);
		return (count + temp);
	}
}
