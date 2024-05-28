/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:59 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 19:17:13 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_case_result(char *content, int fd)
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

int	ptr_case_how_big(intptr_t num)
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

int	ptr_case_is_zero(void)
{
	char	*result_arr;
	int		i;

	result_arr = ft_calloc(4, sizeof(char));
	result_arr[0] = '0';
	result_arr[1] = 'x';
	result_arr[2] = '0';
	i = ptr_case_result(result_arr, 1);
	free(result_arr);
	return (i);
}

void	ptr_processor(intptr_t num, char *result_arr, int digit)
{
	int	remainder;

	remainder = 0;
	result_arr[0] = '0';
	result_arr[1] = 'x';
	while (num != 0)
	{
		remainder = (num % 16);
		if (remainder < 10)
			result_arr[digit - 1] = remainder + '0';
		else
			result_arr[digit - 1] = (remainder - 10 + 'a');
		num = num / 16;
		digit -- ;
	}
}

int	ptr_case(intptr_t num)
{
	int			digit;
	char		*result_arr;
	int			i;

	if (num == 0)
		return (ptr_case_is_zero());
	digit = ptr_case_how_big(num) + 2;
	result_arr = ft_calloc(digit + 3, sizeof(char));
	ptr_processor(num, result_arr, digit);
	i = ptr_case_result(result_arr, 1);
	free (result_arr);
	return (i);
}
