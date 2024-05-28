/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:26:04 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:49:45 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (64 < c && c < 91)
		return (1);
	if (96 < c && c < 123)
		return (1);
	if (47 < c && c < 58)
		return (1);
	return (0);
}

// int	main()
// {
// 	int	c;

// 	c = 0;
// 	while(c < 177)
// 	{
// 		printf("r%d:%c,%d\n",c,c,ft_isalnum(c));
// 		c++;
// 	}
// }