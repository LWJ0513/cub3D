/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:18:48 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/13 14:39:31 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	void	*add;

	add = ptr;
	while (num--)
	{
		*(unsigned char *)ptr = (unsigned char)value;
		ptr++;
	}
	return (add);
}
