/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:03:42 by sooyang           #+#    #+#             */
/*   Updated: 2023/08/08 21:45:32 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file(char *file, t_parsing *parse)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
		return (0);
	if (ft_strncmp(file + (i - 4), ".cub", 4) != 0)
		return (0);
	parse->fd = open(file, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	parse->file_path = file;
	return (1);
}

int	init_parse(t_parsing *parse)
{
	int	i;

	i = -1;
	parse->identifier_list = (int *)malloc(sizeof(int) * 6);
	if (!parse->identifier_list)
		return (0);
	while (++ i < 6)
		parse->identifier_list[i] = 0;
	parse->identifier_count = 0;
	parse->is_empty = 0;
	parse->start_line = NULL;
	parse->image_path = (char **)malloc(sizeof(char *) * 4);
	if (!parse->image_path)
	{
		free(parse->identifier_list);
		return (0);
	}
	return (1);
}

void	init_data(t_data *data)
{
	data->direction = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->dir_x = 0;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0;
	data->move_speed = 0.2;
	data->rot_speed = 0.1;
	data->width = 0;
	data->height = 0;
	data->ceil_color = 0;
	data->floor_color = 0;
}

int	alloc_data(t_data *data, t_parsing *parse)
{
	data->rgb_ceil_color = (int *)malloc(sizeof(int) * 3);
	if (!data->rgb_ceil_color)
	{
		free(parse->identifier_list);
		free(parse->image_path);
		return (0);
	}
	data->rgb_floor_color = (int *)malloc(sizeof(int) * 3);
	if (!data->rgb_floor_color)
	{
		free(parse->identifier_list);
		free(parse->image_path);
		free(data->rgb_ceil_color);
		return (0);
	}
	data->images = (t_image *)malloc(sizeof(t_image) * 4);
	if (!data->images)
	{
		free(parse->identifier_list);
		free(parse->image_path);
		free(data->rgb_ceil_color);
		free(data->rgb_floor_color);
		return (0);
	}
	return (1);
}
