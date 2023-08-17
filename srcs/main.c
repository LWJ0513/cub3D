/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:48 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/17 13:59:04 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(){
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	atexit(leaks);	
	t_data		data;
	t_parsing	parse;

	parsing(argc, argv, &data, &parse);
	open_window(&data);
}
