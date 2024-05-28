/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:32:24 by junhhong          #+#    #+#             */
/*   Updated: 2023/11/24 15:32:20 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;

	i = 0;
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (dest > src)
	{
		while (n --)
			temp_dest[n] = temp_src[n];
	}
	if (src > dest)
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i ++ ;
		}
	}
	return (dest);
}

// int	main()
// {
// 	char src[] = "this is no"; // 10
// 	char dest[] = "oooooooooo"; // 10
// 	int num = 12;
// 	printf("before change dest :: %s\n",dest);
// 	ft_memmove(dest, src ,num);
// 	printf("changed dest :: %s\n",dest);
// 	printf("RESULT (ALWAYS DEST) :: %s\n",ft_memmove(dest, src ,num));
// 	//printf("original :: %s\n", memmove(dest, src, num));
// }