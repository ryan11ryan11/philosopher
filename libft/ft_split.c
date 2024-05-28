/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:26:14 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:47:24 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	how_many_arr(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count ++ ;
			while (s[i] != c && s[i] != '\0')
				i ++ ;
		}
		while (s[i] == c && s[i] != '\0')
			i ++ ;
	}
	return (count);
}

static char	**allocation(char **result, char *s, char c, int len_s)
{
	int	i;
	int	len;
	int	k;

	k = 0;
	len = 0;
	i = 0;
	while (i < len_s)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				i ++ ;
				len ++ ;
			}
			result[k] = ft_substr(s, i - len, len);
			k ++ ;
			len = 0;
		}
		i ++ ;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_arr;
	char	**result;
	int		len_s;

	len_s = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	num_arr = how_many_arr((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (num_arr + 1));
	if (!result)
		return (NULL);
	allocation(result, (char *)s, c, len_s);
	if (!result)
		return (NULL);
	result[num_arr] = NULL;
	return (result);
}

// int main()
// {
// 	char s[] = "       hello this is no  "; // 24
// 	char c = ' ';
// 	char **result = ft_split(s,c);
// 	// i = 0;
// 	// while(i < num_c + 1)
// 	// {
// 	// 	printf("%s\n", result[i]);
// 	// 	i ++ ;
// 	// }
// 	// return (result);
// 	// ----
// 	int j = 0;
// 	while(result[j] != NULL)
// 	{
// 		printf("result[%d] = %s\n", j, result[j]);
// 		j ++ ;
// 	}
// }
