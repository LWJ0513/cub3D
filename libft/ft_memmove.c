/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:39:16 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 20:11:25 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;

	dst1 = (unsigned char *)dst;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (dst <= src)
	{
		i = -1;
		while (++i < len)
			dst1[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = len - 1;
		while (0 < i)
		{
			dst1[i] = ((unsigned char *)src)[i];
			i--;
		}
		dst1[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
