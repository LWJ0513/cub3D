/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:50:18 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 15:55:27 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*src2;

	i = 0;
	str = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		*str = *src2;
		str++;
		src2++;
		i++;
	}
	return (dst);
}
