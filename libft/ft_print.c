/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:12:37 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/21 12:47:31 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	switch_case(char content, va_list ap)
{
	int	len_result;

	len_result = 0;
	if (content == 'c')
		len_result = case_char(va_arg(ap, int), 1, 0);
	else if (content == '%')
		len_result = case_char('%', 1, 1);
	else if (content == 's')
		len_result = case_sentence(va_arg(ap, char *), 1, 0, 0);
	else if (content == 'd' || content == 'i')
		len_result = case_sentence(ft_itoa(va_arg(ap, int)), 1, 0, 1);
	else if (content == 'p')
		len_result = ptr_case(va_arg(ap, unsigned long long));
	else if (content == 'u')
		len_result = case_u(va_arg(ap, unsigned int));
	else if (content == 'x')
		len_result = decitohex(va_arg(ap, unsigned long long), 1);
	else if (content == 'X')
		len_result = decitohex(va_arg(ap, unsigned long long), 2);
	return (len_result);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		total_len;

	va_start(ap, s);
	total_len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i ++ ;
			total_len = total_len + switch_case(s[i], ap);
			i ++ ;
		}
		else if (s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i ++ ;
			total_len ++ ;
		}
	}
	va_end(ap);
	return (total_len);
}

// int main()
// {
// 	//int c = 0;
// 	char *ptr;
// 	//uintptr_t ptrptr;

// 	ptr = ft_strdup("dddddd");
// 	printf("original:%p %p\n", ptr, ptr);
// 	ft_printf("original:%p %p\n", ptr, ptr);
// }