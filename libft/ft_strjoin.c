/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:29:37 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 16:29:19 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp_s;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	temp_s = (char *)malloc((len_s1 + len_s2 + 1) * (sizeof(char)));
	if (!temp_s)
		return (NULL);
	ft_memcpy(temp_s, s1, len_s1);
	ft_memcpy((temp_s + len_s1), s2, len_s2);
	temp_s[len_s1 + len_s2] = '\0';
	return (temp_s);
}

// int main()
// {
// 	char s1[] = "1234567487894";
// 	char s2[] = " a bcdeeeeeeeeeeeeeefdsz";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }