/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:03:29 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 20:01:49 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	minus;
	int	num;

	num = 0;
	minus = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (0x2F < *str && *str < 0x3A)
		num = 10 * num + *str++ - '0';
	return (num * minus);
}
