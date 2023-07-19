/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:06:31 by wonlim            #+#    #+#             */
/*   Updated: 2022/12/05 19:50:50 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	div_int_hexa(unsigned int num, char c, int *i)
{
	if (num > 15)
		div_int_hexa(num / 16, c, i);
	if (num % 16 < 10)
		ft_putchar(0x30 + num % 16, i);
	else
		ft_putchar(c + num % 16 - 10, i);
}

void	div_long_hexa(unsigned long num, int step, int *i)
{
	if (num > 15)
		div_long_hexa(num / 16, step++, i);
	if (step == 0)
		ft_putstr("0x", i);
	if (num % 16 < 10)
		ft_putchar(0x30 + num % 16, i);
	else
		ft_putchar('a' + num % 16 - 10, i);
}
