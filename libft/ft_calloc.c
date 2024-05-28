/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:37:15 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/17 14:03:26 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, nmemb * size);
	return (result);
}

// int main()
// {
// 	//arr가 int일 때//
// 	int *arr1; // int array
// 	int *arr2;
// 	char *arr3; 
// 	char *arr4;  
// 	int nmemb;
// 	int i = 0;

// 	nmemb = 10;
// 	arr1 = (int *)ft_calloc(nmemb, sizeof(int));
// 	arr2 = (int *)calloc(nmemb, sizeof(int));
// 	arr3 = (char *)ft_calloc(nmemb, sizeof(char));
// 	arr4 = (char *)calloc(nmemb, sizeof(char));
// 	while(i < nmemb)
// 	{
// 		printf("my     arr[%d]:%d\n", i, arr1[i]);
// 		printf("origin arr[%d]:%d\n", i, arr2[i]);
// 		i++;
// 	}
// 	printf("my     arr :: %s\n", arr3);
// 	printf("origin arr :: %s\n", arr4);
// }