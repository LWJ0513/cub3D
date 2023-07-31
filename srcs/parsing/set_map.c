/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:27:41 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/31 21:01:47 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	alloc_map(t_data *data, t_parsing *parse)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	data->map = (char **)malloc(sizeof(char *) * data->height);
	while (data->map[++i])
		data->map[i] = (char *)malloc(sizeof(char) * data->width);
	i = -1;
	while (1)
	{
		line = get_next_line(parse->fd);
		if (ft_strncmp(line, parse->start_line, data->width) == 0)
			break ;
		free(line);
	}
	while (++i < data->height)
	{
		j = -1;
		while (line[++j])
			data->map[i][j] = line[j];
		j--;
		while (++j < data->width)
			data->map[i][j] = ' ';
		data->map[i][j] = 0;
		free(line);
		line = get_next_line(parse->fd);
	}
	free(line);
	close(parse->fd);
	return (1);
}

int	set_map(t_data *data, t_parsing *parse)
{
	parse->fd = open(parse->file_path, O_RDONLY);
	if (!parse->fd)
		return (0);
	//파일 최대 width/height로 읽어서 map에 값 넣기
	if (!alloc_map(data, parse))
		return (0);
	// 플레이어 위치 세팅
	return (1);
}