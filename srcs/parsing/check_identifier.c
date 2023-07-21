/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:39:46 by sooyang           #+#    #+#             */
/*   Updated: 2023/07/21 15:12:31 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*gnl 돌며 현재 파일에 식별자가 올바르게 있는지 찾아야함
	- 길이 0일 때 -> fail
	- 문자 두개 안 나올 때 -> fail
	- split
	- 나온 문자로 식별자 분류 & 카운트
	- 이미지 설정
	- 컬러 설정
*/
int	check_identifier(t_data *data, t_parsing *parse)
{
	char	*line;

	while (6 > parse->identifier_count)
	{
		line = get_next_line(parse->fd);
		if (line == EOF)
		{
			close(parse->fd);
			free(line);
			return (0);
		}
	}
}