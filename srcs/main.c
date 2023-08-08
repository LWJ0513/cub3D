/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:48 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/08 17:33:40 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data		data;
	t_parsing	parse;

	parsing(argc, argv, &data, &parse);
	open_window(&data);
	// mlx_destroy_image(data.mlx, data.image.img);
}
