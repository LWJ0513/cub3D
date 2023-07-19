/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:49:56 by wonlim            #+#    #+#             */
/*   Updated: 2022/12/06 20:53:25 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	len_s1;

	len = 0;
	if (s1)
	{
		len += ft_strlen(s1);
		len_s1 = ft_strlen(s1);
	}
	if (s2)
		len += ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i--;
	while (++i < len)
		str[i] = s2[i - len_s1];
	str[i] = '\0';
	return (str);
}
