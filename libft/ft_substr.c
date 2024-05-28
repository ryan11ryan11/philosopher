/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:07 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/17 16:18:28 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp_s;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		len = 0;
	if (!s)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	temp_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp_s)
		return (NULL);
	while (i < len)
	{
		temp_s[i] = s[start];
		start ++ ;
		i ++ ;
	}
	temp_s[i] = '\0';
	return (temp_s);
}

// int main()
// {
// 	char s[] = "hola";
// 	int start = 4;
// 	int len = 200;
// 	printf("%s\n", ft_substr(s, start , len));
// }