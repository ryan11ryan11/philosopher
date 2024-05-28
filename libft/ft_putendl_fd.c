/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:42:00 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/15 16:17:43 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	newline;

	newline = '\n';
	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		i ++ ;
	}
	write(fd, &newline, sizeof(char));
}

// int	main()
// {
// 	char s[] = "hello!";
// 	int fd;

// 	fd = 1;
// 	ft_putendl_fd(s, fd);
// }