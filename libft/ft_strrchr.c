/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:53:23 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/16 18:34:55 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i ++ ;
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i -- ;
	}
	return (NULL);
}

// int	main()
// {
// 	char s[] = "x this x is x finder";
// 	int c = 't' + 256;
// 	printf("my :: %s\n", ft_strrchr(s,c));
// 	printf("origin :: %s\n", strrchr(s,c));
// }