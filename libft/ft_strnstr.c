/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:50:35 by wonlim            #+#    #+#             */
/*   Updated: 2023/05/17 06:11:57 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i + needle_len <= len && *haystack)
	{
		if (!haystack && needle)
			return (0);
		if ((haystack[0] == needle[0]) \
		&& !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
