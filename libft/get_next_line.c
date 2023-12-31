/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:30:25 by wonlim            #+#    #+#             */
/*   Updated: 2023/07/22 02:20:52 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl(int size, int fd)
{
	char	*str;
	char	buf[1];
	int		check;

	check = read(fd, buf, 1);
	if (check < 0 || (check == 0 && size == 0))
		return (0);
	if (check == 0 || *buf == '\n')
		str = malloc(size + 2);
	else
		str = gnl(size + 1, fd);
	if (str)
	{
		str[size] = *buf;
		if (*buf == '\n')
			str[size + 1] = 0;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	return (gnl(0, fd));
}
