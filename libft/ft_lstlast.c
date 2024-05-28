/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:00:11 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/07 16:12:54 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

// int	main()
// {
// 	t_list *lst;
// 	lst = NULL;
// 	// t_list *block1;
// 	// t_list *block2;
// 	// lst = (t_list *)malloc(sizeof(t_list));
// 	// lst -> content = "first block";
// 	// block1 = (t_list *)malloc(sizeof(t_list));
// 	// block1 -> content = "block1";
// 	// block2 = (t_list *)malloc(sizeof(t_list));
// 	// lst -> next = block1;
// 	// block1 -> next = block2;
// 	// block2 -> next = NULL;
// 	ft_lstlast(lst);
// }