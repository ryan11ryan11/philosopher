/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:00:36 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/15 19:01:45 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	plusminus(char *nptr, int i)
{
	if (nptr[i] == '-')
	{
		i ++ ;
		return (-1);
	}
	if (nptr[i] == '+')
	{
		i ++ ;
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	int		digit;
	int		a;

	result = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i ++ ;
	a = plusminus((char *)nptr, i);
	if (nptr[i] == '+' || nptr[i] == '-')
		i ++ ;
	if (48 > nptr[i] || nptr[i] > 57)
		return (0);
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		digit = (nptr[i] - '0');
		result = result * 10 + digit;
		i ++ ;
	}
	return (result * a);
}

// int main()
// {
// 	char nptr1[] = " \t\v\n\r\f123";
// 	char nptr2[] = " \t\v\n\r\f123";
// 	printf("my :: %d\n",ft_atoi(nptr1));
// 	printf("or :: %d\n",atoi(nptr2));
// }