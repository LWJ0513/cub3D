/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:00:15 by sooyang           #+#    #+#             */
/*   Updated: 2023/08/08 17:37:38 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_map(char *line, int fd, int exitcode)
{
	close(fd);
	free(line);
	return (exitcode);
}

int	check_map(t_data *data, t_parsing *parsing, char *line)
{
	int	i;

	i = -1;
	if (ft_strlen(line) == 1 && parsing->is_empty == 0)
		return (1);
	if (ft_strlen(line) == 1 && parsing->is_empty == 1)
		return (0);
	while (line[++i])
	{
		if (data->direction != 0 && (line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'W' || line[i] == 'E'))
			return (0);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
		line[i] == 'E')
			data->direction = line[i];
		else if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && \
		line[i] != '\n')
			return (0);
	}
	data->height++;
	parsing->is_empty = 1;
	if (data->width < i)
		data->width = i;
	return (1);
}

int	validate_map(t_data *data, t_parsing *parsing)
{
	char	*line;

	while (1)
	{
		line = get_next_line(parsing->fd);
		if (!line && parsing->is_empty == 0)
			return (close_map(line, parsing->fd, 0));
		if (line && parsing->is_empty == 1 && ft_strlen(line) == 1)
			return (close_map(line, parsing->fd, 0));
		if (!line && parsing->is_empty == 1)
			return (close_map(line, parsing->fd, 1));
		if (check_map(data, parsing, line) == 0)
			return (close_map(line, parsing->fd, 0));
		if (data->height == 1)
			parsing->start_line = ft_strdup(line);
		free(line);
	}
}
