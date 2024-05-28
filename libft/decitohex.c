/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decitohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:41:13 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 19:17:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	decitohex_result(char *content, int fd)
{
	int	i;

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

int	decitohex_how_big(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i ++ ;
	}
	return (i);
}

void	processor(unsigned int num, char *result_arr, int bigorsmall, int digit)
{
	int	remainder;

	remainder = 0;
	while (num != 0)
	{
		remainder = (num % 16);
		if (remainder < 10)
			result_arr[digit - 1] = remainder + '0';
		else
		{
			if (bigorsmall == 1)
				result_arr[digit - 1] = (remainder - 10 + 'a');
			if (bigorsmall == 2)
				result_arr[digit - 1] = (remainder - 10 + 'A');
		}
		num = num / 16;
		digit -- ;
	}
}

int	decitohex(unsigned int num, int bigorsmall)
{
	int		digit;
	char	*result_arr;
	int		i;

	digit = decitohex_how_big(num);
	if (num == 0)
		return (decitohex_result("0", 1));
	result_arr = ft_calloc(digit + 1, sizeof(char));
	processor(num, result_arr, bigorsmall, digit);
	i = decitohex_result(result_arr, 1);
	free (result_arr);
	return (digit);
}
