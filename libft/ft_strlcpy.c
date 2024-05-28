/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:48:58 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/15 17:04:36 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size || !dst || !src)
		return (ft_strlen(src));
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i ++ ;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main()
// {
// 	char dst[] = "";
// 	char src[] = "av";
// 	printf("my result :: %zu\n",ft_strlcpy(dst, src, 5));
// 	printf("%s\n", dst);
// 	//printf("original :: %zu\n",strlcpy(dst, src, 10));
// 	//printf("original :: %lu\n", strlcpy(dst, src, -5));
// }