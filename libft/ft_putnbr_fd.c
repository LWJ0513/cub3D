/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:26:40 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/18 21:20:07 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_num(int nb, int fd)
{
	char	ascii;

	if (nb >= 10)
		get_num(nb / 10, fd);
	ascii = nb % 10 + 0x30;
	write(fd, &ascii, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n > -1)
		get_num(n, fd);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		write(fd, "-", 1);
		get_num(-n, fd);
	}
}
