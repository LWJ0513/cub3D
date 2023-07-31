/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:27:41 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/31 21:15:39 by sooyang          ###   ########.fr       */
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

// 시작지점 (1,0 E)(-1,0 W)(0,-1 S)(0,1 N)
void	check_direction(t_data *data, char dir)
{
	if (dir == 'E')
		data->dir_x = 1;
	else if (dir == 'W')
		data->dir_x = -1;
	else if (dir == 'S')
		data->dir_y = -1;
	else if (dir == 'N')
		data->dir_y = 1;
}

int	init_player(t_data *data, t_parsing *parse)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->map[i][j] == '0' || data->map[i][j] == data->direction)
			{
				if (j <= 0 || i <= 0 || j >= data->width - 1 || \
				i >= data->height - 1)
					return (0);
				else
					if (data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' '\
					|| data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ')
						return (0);
			}
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				check_direction(data, data->map[i][j]);
				data->pos_x = j + 0.5;
				data->pos_y = i + 0.5;
			}
		}
	}
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
	if (!init_player(data, parse))
		return (0);
	return (1);
}