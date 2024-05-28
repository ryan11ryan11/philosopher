/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:27:27 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 19:17:39 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	case_char(int c, int fd, int is_percent)
{
	char	x;

	if (is_percent == 1)
	{
		x = '%';
		write(fd, &x, sizeof(char));
		return (1);
	}
	else
	{
		write(fd, &c, sizeof(char));
		return (1);
	}
}
