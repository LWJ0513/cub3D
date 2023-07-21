/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:45 by wonlim            #+#    #+#             */
/*   Updated: 2023/07/20 23:56:25 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_image {
	int		width;
	int		heigth;
	int		line_length;
	int		bpp;
	int		endian;
	int		*addr;
	void	*img;
}	t_image;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_image	*images;
	int		*ceil_color;
	int		*floor_color;
	char	direction;
	double	x;
	double	y;
	int		width;
	int		height;
	char	**map;
}	t_data;

typedef struct s_parsing {
	char	*file_path;
	int		fd;
	int		identifier_count;
	int		*identifier_list;
	int		is_empty;
	char	*start_line;
	char	**image_path;
}	t_parsing;

//error
void	ft_error(char *msg);

//init_data
int		check_file(char *file, t_parsing *parse);
int		init_parse(t_parsing *parse);
void	init_data(t_data *data);
int		alloc_data(t_data *data, t_parsing *parse);

//check_identifier
int		check_identifier(t_data *data, t_parsing *parse);

#endif