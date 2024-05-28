/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:43 by junhhong          #+#    #+#             */
/*   Updated: 2023/11/23 15:35:02 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c)
			return ((temp_s + i));
		i ++ ;
	}
	return (NULL);
}

// int	main()
// {
// 	char s[] = "this \0z dd";
// 	int c = 'z';
// 	int n = 1000;
// 	printf("my     :: %s\n", ft_memchr(s,c,n));
// 	printf("origin :: %s\n", memchr(s,c,n));
// }