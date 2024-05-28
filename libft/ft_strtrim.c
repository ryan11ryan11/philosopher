/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:42:05 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/17 17:03:48 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	is_txt(char txt, char *set)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == txt)
		{
			count ++ ;
			return (count);
		}
		j ++ ;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = 0;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (!s1 || !set)
		return (NULL);
	while (is_txt(s1[i], (char *)set) != 0 && s1[i] != '\0')
		i ++ ;
	while (is_txt(s1[j - 1], (char *)set) != 0 && j > i)
		j -- ;
	result = ft_substr((char *)s1, i, j - i);
	return (result);
}

// int main()
// {
// 	char s1[] = "avcccc"; // 5
// 	char set[] = ""; // expected :: xxaxx
// 	printf("final::%s\n", ft_strtrim(s1, set));
// }