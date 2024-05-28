/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:03:34 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 19:17:47 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	case_u_result(char *content, int fd)
{
	unsigned int	i;

	i = 0;
	if (!content)
		return (0);
	while (content[i])
	{
		write(fd, &content[i], sizeof(char));
		i ++ ;
	}
	return (i);
}

unsigned int	case_u_ss(unsigned int n)
{
	unsigned int	i;

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

char	*case_u_maker(unsigned int n, char *arr, unsigned int len)
{
	unsigned int	temp_n;

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

unsigned int	case_u(unsigned int n)
{
	unsigned int	len;
	unsigned int	temp_n;
	char			*arr;
	unsigned int	result_num;

	if (n > 4294967295)
		return (0);
	len = case_u_ss(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[len] = '\0';
	temp_n = n;
	if (n >= 0)
		case_u_maker(n, arr, len);
	result_num = case_u_result(arr, 1);
	free (arr);
	return (result_num);
}

// int main()
// {
// 	printf("result:%s\n",case_u(4294967296));
// }