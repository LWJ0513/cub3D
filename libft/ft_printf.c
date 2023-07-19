/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:39:08 by wonlim            #+#    #+#             */
/*   Updated: 2022/12/05 19:56:24 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_char(char c, int *i)
{
	if (c == '%')
		return (1);
	else
		ft_putchar(c, i);
	return (0);
}

void	check_type(char c, va_list *ap, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*ap, int), i);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), i);
	else if (c == 'p')
		div_long_hexa(va_arg(*ap, unsigned long), 0, i);
	else if (c == 'd' || c == 'i')
		ft_printf_itoa(va_arg(*ap, int), i);
	else if (c == 'u')
		print_itoa((unsigned int)va_arg(*ap, unsigned int), i);
	else if (c == 'x')
		div_int_hexa(va_arg(*ap, long), 'a', i);
	else if (c == 'X')
		div_int_hexa(va_arg(*ap, long), 'A', i);
	else if (c == '%')
		ft_putchar('%', i);
	else
		return ;
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, args);
	i = 0;
	while (*args)
	{
		if (check_char(*args, &i))
		{
			args++;
			check_type(*args, &ap, &i);
		}
		args++;
	}
	return (i);
}
