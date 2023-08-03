/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:48 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/03 20:57:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data		data;
	t_parsing	parse;

	// todo 구조체 초기화 (planeX, planeY 초기화)
	parsing(argc, argv, &data, &parse);
	//open_window(&data);
}
