/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:48:54 by wonlim            #+#    #+#             */
/*   Updated: 2023/07/22 02:29:22 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (string[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = string[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
