/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_sentence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:13:02 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 19:17:44 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size || !dst || !src)
		return (ft_strlen(src));
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i ++ ;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	case_sentence_null(char *content)
{
	int		i;
	char	c[7];

	i = 0;
	ft_strlcpy(c, "(null)", 7);
	while (c[i])
	{
		write(1, &(c[i]), sizeof(char));
		i ++ ;
	}
	free (content);
	return (6);
}

void	free_if_1(char *content, int is_di)
{
	if (is_di == 1)
		free (content);
}

int	case_sentence(char *content, int fd, int is_char, int is_di)
{
	int	i;

	i = 0;
	if (!content)
		return (case_sentence_null(content));
	if (is_char == 1)
	{
		if (ft_strlen(content) != 1)
		{
			free_if_1(content, is_di);
			return (0);
		}
		write(fd, &content[0], sizeof(char));
		free_if_1(content, is_di);
		return (1);
	}
	while (content[i])
	{
		write(fd, &content[i], sizeof(char));
		i ++ ;
	}
	free_if_1(content, is_di);
	return (i);
}
