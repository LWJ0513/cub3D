/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:48 by wonlim            #+#    #+#             */
/*   Updated: 2023/07/21 21:50:10 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_n_init(int argc, char **argv, t_data *data, t_parsing *parse)
{
	if (argc != 2)
		ft_error("invalid argument");
	if (!check_file(argv[1], parse))
		ft_error("invalid file extension");
	if (!init_parse(parse))
		ft_error("fail init");
	init_data(data);
	if (!alloc_data(data, parse))
		ft_error("fail init");
}

int main(int argc, char **argv)
{
	t_data		data;
	t_parsing	parse;

	check_file_n_init(argc, argv, &data, &parse);
	if (!check_identifier(&data, &parse))
		ft_error("invalid identified");
	data.mlx = mlx_init();
	//맵 유효성 검사
	
	//모서리 검사
}