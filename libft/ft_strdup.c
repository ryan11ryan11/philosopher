/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:25:13 by junhhong          #+#    #+#             */
/*   Updated: 2023/11/27 10:53:40 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*arr;

	len_s = ft_strlen((char *)s);
	arr = (char *)malloc((len_s + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	ft_memmove(arr, (char *)s, len_s);
	arr[len_s] = '\0';
	return (arr);
}

// int main()
// {
// 	char s[] = "012345";
// 	printf("my       :: %s\n",ft_strdup(s));
// 	printf("original :: %s\n",strdup(s));
// }