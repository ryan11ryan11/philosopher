/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:20:48 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/07 15:58:49 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst -> next;
		i ++ ;
	}
	return (i);
}

// int	main()
// {
// 	t_list *lst;
// 	t_list *block1;
// 	t_list *block2;
// 	lst = (t_list *)malloc(sizeof(t_list));
// 	lst -> content = "first block";
// 	block1 = (t_list *)malloc(sizeof(t_list));
// 	block1 -> content = "block1";
// 	block2 = (t_list *)malloc(sizeof(t_list));
// 	lst -> next = block1;
// 	block1 -> next = block2;
// 	block2 -> next = NULL;
// 	printf("%d", ft_lstsize(lst));
// }