/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:30:40 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/31 21:17:52 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arg_n_init(int argc, char **argv, t_data *data, t_parsing *parse)
{
	if (argc != 2)
		ft_error("invalid argument");
	if (!check_file(argv[1], parse))
		ft_error("fail open");
	if (!init_parse(parse))
		ft_error("fail init");
	init_data(data);
	if (!alloc_data(data, parse))
		ft_error("fail init");
}

void	parsing(int argc, char **argv, t_data *data, t_parsing *parse)
{
	arg_n_init(argc, argv, data, parse);
	if (!check_identifier(data, parse))
		ft_error("invalid identified");
	data->mlx = mlx_init();
	if (!check_image(data, parse))
		ft_error("fail to load images");
	if (!validate_map(data, parse))
		ft_error("fail to load map");
	if (!set_map(data, parse))
		ft_error("fail to set map");
	// 바닥, 천장 color 16진수 변환
}
