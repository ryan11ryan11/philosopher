/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:02:08 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/21 12:38:43 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

static int	ss(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (9 < n)
	{
		n = n / 10;
		i ++ ;
	}
	return (i + 1);
}

static char	*maker(int n, char *arr, int len)
{
	int	temp_n;

	temp_n = n;
	while (len > 0)
	{
		temp_n = temp_n % 10;
		arr[len - 1] = temp_n + '0';
		n = (n - temp_n) / 10;
		len -- ;
		temp_n = n;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*arr;

	len = 0;
	len = ss(n);
	if (n < 0)
		len ++ ;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	if (n < 0)
	{
		n = n * -1;
		maker(n, arr, len);
		arr[0] = '-';
		return (arr);
	}
	if (n >= 0)
		maker(n, arr, len);
	return (arr);
}

// int	main()
// {
// 	int	number;

// 	number = 123456789;
// 	printf ("%s\n",ft_itoa(number));
// }