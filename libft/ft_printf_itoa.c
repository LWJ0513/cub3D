/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:04:55 by wonlim            #+#    #+#             */
/*   Updated: 2022/12/05 19:51:05 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_itoa(long num, int *i)
{
	if (num > 9)
		print_itoa(num / 10, i);
	ft_putchar(num % 10 + '0', i);
}

void	ft_printf_itoa(int n, int *i)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar('-', i);
		num *= -1;
	}
	print_itoa(num, i);
}
