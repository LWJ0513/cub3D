/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:17:50 by sooyang           #+#    #+#             */
/*   Updated: 2023/08/16 22:27:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_parse(t_parsing *parse)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(parse->image_path[i]);
	free(parse->image_path);
	free(parse->identifier_list);
	free(parse->start_line);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->height)
		free(data->map[i]);
	free(data->map);
	free(data->rgb_ceil_color);
	free(data->rgb_floor_color);
	free(data->images);
}
