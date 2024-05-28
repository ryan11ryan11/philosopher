/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:06 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/15 14:51:22 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = f(i, s[i]);
		i ++ ;
	}
	arr[i] = '\0';
	return (arr);
}

// char f(unsigned int x, char y)
// {
// 	if(x == 's')
// 		y = 'x';
// 	return (x);
// }

// int main()
// {
// 	char s[] = "sfasf";
// 	printf("%s\n", ft_strmapi(s, f));
// }