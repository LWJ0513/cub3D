/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:58:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/21 21:28:53 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error) ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_free(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
}

int	is_two_word(char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	ft_free(tmp);
	if (i != 2)
		return (0);
	return (1);
}

int	is_three_word(char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ',');
	while (tmp[i])
		i++;
	ft_free(tmp);
	if (i != 3)
		return (0);
	return (1);
}