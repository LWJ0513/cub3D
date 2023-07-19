/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:01:45 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 15:01:37 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len1(long long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	long long	num;

	num = (long long)n;
	len = get_len1((long long)n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	else if (num == 0 && len > -1)
		res[0] = '0';
	res[len] = '\0';
	while (num)
	{
		res[--len] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
