/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:53:04 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/07 18:05:57 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp_s;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		len = 0;
	if (!s)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	temp_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp_s)
		return (NULL);
	while (i < len)
	{
		temp_s[i] = s[start];
		start ++ ;
		i ++ ;
	}
	temp_s[i] = '\0';
	return (temp_s);
}

char	*arr_refresh(char *s2, char *s1, int c)
{
	char	*temp;

	temp = NULL;
	if (c >= 0)
	{
		temp = ft_strjoin(s2, s1);
		free (s2);
		s2 = NULL;
	}
	return (temp);
}

char	*arr_trim(char *s2, int read_result, int *i)
{
	int			j;
	char		*trimmed_result;

	j = 0;
	while (s2[*i] != '\0')
	{
		if (s2[*i] == '\n')
		{
			trimmed_result = ft_substr(s2, *i - j, j + 1);
			*i = *i + 1 ;
			return (trimmed_result);
		}
		*i = *i + 1 ;
		j ++ ;
	}
	if ((read_result < BUFFER_SIZE && j > 0))
	{
		trimmed_result = ft_substr(s2, *i - j, j);
		return (trimmed_result);
	}
	*i = *i - j;
	return (NULL);
}

char	*s2_generator(int fd, int *byte_read, int *c, int *i)
{
	char		*s1;
	static char	*s2_2;

	s1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*byte_read = read(fd, s1, BUFFER_SIZE);
	if (s2_2 == NULL || (*c < 0 && *byte_read > 0))
		s2_2 = ft_calloc(sizeof(char), 1);
	if (*c < 0 && *byte_read > 0)
		*c = 0;
	if (*byte_read < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		*i = 0;
		*c = 0;
		free (s2_2);
		s2_2 = NULL;
		free (s1);
		s1 = NULL;
		return (NULL);
	}
	s2_2 = arr_refresh(s2_2, s1, *c);
	ft_memset(s1, 0, BUFFER_SIZE);
	free (s1);
	s1 = NULL;
	return (s2_2);
}

char	*get_next_line(int fd)
{
	char		*s2;
	char		*result;
	static int	i;
	static int	c;
	static int	read_result_index;

	read_result_index = 0;
	s2 = s2_generator(fd, &read_result_index, &c, &i);
	if (s2 == NULL)
		return (NULL);
	result = arr_trim(s2, read_result_index, &i);
	while (result == NULL && read_result_index > 0)
	{
		s2 = s2_generator(fd, &read_result_index, &c, &i);
		result = arr_trim(s2, read_result_index, &i);
	}
	if (read_result_index < BUFFER_SIZE && result == NULL && c == 0)
	{
		free (s2);
		c = -100;
		i = 0;
		s2 = NULL;
		return (result);
	}
	return (result);
}
