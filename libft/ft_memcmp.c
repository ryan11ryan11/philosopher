/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:04:50 by junhhong          #+#    #+#             */
/*   Updated: 2023/11/23 15:29:06 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i ++ ;
	}
	return (0);
}

// int main()
// {
// 	char s1[] = ""; //9 
// 	char s2[] = ""; //9
// 	int n = 5;
// 	printf("mine     :: %d\n", ft_memcmp(s1, s2, n));
// 	printf("original :: %d\n", memcmp(s1, s2, n));
// }