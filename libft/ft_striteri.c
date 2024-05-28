/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:59:45 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/04 11:11:16 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++ ;
	}
}

// void	f(unsigned int i, char *s)
// {
// 	if(s[i] == 's')
// 		s[i] = 'x';
// }

// int	main()
// {
// 	char arr[] = "this is  sssss sentence";
// 	ft_striteri(arr, f);
// }