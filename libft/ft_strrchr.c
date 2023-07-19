/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:50:38 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 20:30:57 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	i = ft_strlen(s);
	str = &s[i];
	while (-1 < i)
	{
		if (*str == (char)c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
