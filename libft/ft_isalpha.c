/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:38 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:49:59 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (64 < c && c < 91)
		return (1);
	if (96 < c && c < 123)
		return (1);
	return (0);
}

// int	main()
// {
// 	int	c;

// 	c = 0;
// 	while(c < 177)
// 	{
// 		printf("r%d:%c,%d\n",c,c,ft_isalpha(c));
// 		c++;
// 	}
// }