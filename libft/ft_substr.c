/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:35:30 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 20:55:19 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
