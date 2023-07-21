/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:39:46 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/21 18:10:30 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	gnl 돌며 현재 파일에 식별자가 올바르게 있는지 찾아야함
	- 길이 0일 때 -> fail(아무것도 없는거)
	- 문자 두개 안 나올 때 -> fail
	- split
	- 나온 문자로 식별자 분류 & 카운트
	- 이미지 설정
	- 컬러 설정
*/

//이 줄이 두개의 문자로 나눠지는지 판단
int	is_two_word(char *line)
{
	
}

//식별자 분류
int	is_identifier(char **identifier)
{
	
}

// 한 줄이 두개의 문자로 나눠지는지 판단 후 split
int	check_line(t_data *data, t_parsing *parse, char *line)
{
	int		check;
	char	**identifier;

	if (!is_two_word(line))
		return (0);
	identifier = ft_split(line, ' ');
	check = is_identifier(identifier);
	if (check >= NO && check <= EA)
	{
		//image 처리
	}
	else if (check == F || check == C)
	{
		//카운트
		//color 처리
	}
	else
	{
		//free identifier
		return (0);
	}
	return (1);
}

int	check_identifier(t_data *data, t_parsing *parse)
{
	char	*line;

	while (6 > parse->identifier_count)
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