/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:39:46 by sooyang           #+#    #+#             */
/*   Updated: 2023/08/08 17:46:55 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_image(t_data *data, t_parsing *parse)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->images[i].img = mlx_xpm_file_to_image(data->mlx, \
		parse->image_path[i], &data->images[i].width, &data->images[i].height);
		if (!data->images[i].img)
			return (0);
		data->images[i].buffer = (int *)mlx_get_data_addr(data->images[i].img, \
		&data->images[i].bits_per_pixel, &data->images[i].size_line, \
		&data->images[i].endian);
		if (!data->images[i].buffer)
			return (0);
	}
	return (1);
}

int	is_identifier(char **identifier, t_parsing *parse)
{
	int	tmp;

	tmp = -1;
	if (ft_strncmp(identifier[0], "NO", 3) == 0)
		tmp = NO;
	else if (ft_strncmp(identifier[0], "SO", 3) == 0)
		tmp = SO;
	else if (ft_strncmp(identifier[0], "WE", 3) == 0)
		tmp = WE;
	else if (ft_strncmp(identifier[0], "EA", 3) == 0)
		tmp = EA;
	else if (ft_strncmp(identifier[0], "F", 2) == 0)
		tmp = F;
	else if (ft_strncmp(identifier[0], "C", 2) == 0)
		tmp = C;
	if (tmp == -1 || (tmp != -1 && parse->identifier_list[tmp] == 1))
		return (-1);
	parse->identifier_count++;
	if (6 < parse->identifier_count)
		return (-1);
	parse->identifier_list[tmp] = 1;
	return (tmp);
}

int	set_color(char **identifier, t_data *data, int check)
{
	int		i;
	int		n;
	char	**color;

	if (!is_three_word(identifier[1]))
		return (0);
	color = ft_split(identifier[1], ',');
	i = -1;
	while (++i < 3)
	{
		n = ft_atoi(color[i]);
		if (n < 0 || n > 255)
		{
			ft_free(color);
			return (0);
		}
		if (check == F)
			data->rgb_floor_color[i] = n;
		else if (check == C)
			data->rgb_ceil_color[i] = n;
	}
	ft_free(color);
	return (1);
}

int	check_line(t_data *data, t_parsing *parse, char *line)
{
	int		check;
	char	**identifier;

	if (ft_strlen(line) == 1)
		return (1);
	if (!is_two_word(line))
		return (0);
	identifier = ft_split(line, ' ');
	check = is_identifier(identifier, parse);
	if (check >= NO && check <= EA)
		parse->image_path[check] = ft_strdup(identifier[1]);
	if (check == F || check == C)
	{
		if (!set_color(identifier, data, check))
		{
			ft_free(identifier);
			return (0);
		}
	}
	ft_free(identifier);
	if (check == -1)
		return (0);
	return (1);
}

int	check_identifier(t_data *data, t_parsing *parse)
{
	char	*line;

	while (parse->identifier_count < 6)
	{
		line = get_next_line(parse->fd);
		if (line == 0)
		{
			close(parse->fd);
			free(line);
			return (0);
		}
		if (!check_line(data, parse, line))
		{
			close(parse->fd);
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}