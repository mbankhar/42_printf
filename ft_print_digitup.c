/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digitup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:50 by mbankhar          #+#    #+#             */
/*   Updated: 2024/03/25 09:51:35 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digitup(long n, int base)
{
	int		count;
	char	*symbols;
	int		temp;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (print_digitup(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = print_digitup(n / base, base);
		if (count == -1)
			return (-1);
		temp = print_digitup(n % base, base);
		if (temp == -1)
			return (-1);
		return (count + temp);
	}
}
