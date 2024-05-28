/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:28:04 by junhhong          #+#    #+#             */
/*   Updated: 2023/11/28 11:48:36 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	if (!dest_ptr && !src_ptr)
		return (dest);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i ++ ;
	}
	return (dest);
}

// int main()
// {
// 	char dest[] = "1234";
// 	char src[] = "0";
// 	printf("%s\n",ft_memcpy(dest, src, 0));
// 	printf("%s\n",memcpy(dest, src, 0));
// }
