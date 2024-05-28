/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:10 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/13 12:08:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s ++ ;
	}
	if (*s == (unsigned char) c)
		return ((char *)s);
	return (NULL);
}

// int	main()
// {
// 	char s[] = "dsfsdf";
// 	int c = '\0';
// 	printf("my :: %s\n", ft_strchr(s,c));
// 	printf("origin :: %s\n", strchr(s,c));
// }