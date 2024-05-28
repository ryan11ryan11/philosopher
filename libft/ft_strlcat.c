/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:41:56 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/13 11:57:04 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	result;

	result = ft_strlen(dst) + ft_strlen(src);
	j = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (j + dst_len + 1 < size && src[j] != '\0')
	{
		dst[dst_len + j] = src[j];
		j ++ ;
	}
	dst[dst_len + j] = '\0';
	return (result);
}

// int	main()
// {
// 	char dst[12] = ""; // 11
// 	char src[] = ""; // 4
// 	int size = 12;
// 	printf("my  ::%zu\n",ft_strlcat(dst, src, size));
// 	printf("or  ::%zu\n",strlcat(dst, src, size));
// 	printf("%s\n",dst);
// }