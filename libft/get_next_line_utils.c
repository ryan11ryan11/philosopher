/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:00:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/22 16:04:28 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++ ;
	return (i);
}

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i ++ ;
	}
	return (s);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*result;

// 	if (nmemb == 0 || size == 0)
// 	{
// 		nmemb = 1;
// 		size = 1;
// 	}
// 	result = malloc(nmemb * size);
// 	if (!result)
// 		return (NULL);
// 	ft_memset(result, 0, nmemb * size);
// 	return (result);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*temp_s;
// 	int		len_s1;
// 	int		len_s2;

// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	temp_s = (char *)malloc((len_s1 + len_s2 + 1) * (sizeof(char)));
// 	if (!temp_s)
// 		return (NULL);
// 	ft_memcpy(temp_s, s1, len_s1);
// 	ft_memcpy((temp_s + len_s1), s2, len_s2);
// 	temp_s[len_s1 + len_s2] = '\0';
// 	return (temp_s);
// }
