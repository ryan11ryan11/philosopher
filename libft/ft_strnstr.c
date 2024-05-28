/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:03 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/17 16:25:42 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0 || ft_strlen(little) > ft_strlen(big))
		return (NULL);
	while (i < len && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp((big + i), (char *)little, ft_strlen(little)) == 0)
			return ((char *)big + i);
		i ++ ;
	}
	return (NULL);
}

// int main()
// {
// 	char big[] = "haystack";
// 	char little[] = "a";
// 	int len = 2;
// 	printf("mine     :: %s\n",ft_strnstr(big, little, len));
// 	printf("original :: %s\n",strnstr(big, little, len));
// }