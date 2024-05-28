/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:02 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:55:24 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!temp)
	{
		(*lst) = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	(temp)->next = new;
}

// int	main()
// {
//     t_list	*begin;
// 	t_list	*elem;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	t_list	*elem4;

// 	//begin = ft_lstnew("begin");
// 	elem = ft_lstnew("elem");
// 	elem2 = ft_lstnew("elem2");
// 	elem3 = ft_lstnew("elem3");
// 	elem4 = ft_lstnew("elem4");

// 	begin = NULL;
//     ft_lstadd_back(&begin, elem);
//     ft_lstadd_back(&begin, elem2);
//     ft_lstadd_back(&begin, elem3);
//     ft_lstadd_back(&begin, elem4);
//     while (begin)
//     {
//         printf("%s\n",begin -> content);
//         begin = begin->next;
// 	}
// }

// int main()
// {
// 	t_list	*lst;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*new;
// 	lst = ft_lstnew("lst");
// 	node1 = ft_lstnew("node1");
// 	node2 = ft_lstnew("node2");
// 	node3 = ft_lstnew("node3");
// 	new = ft_lstnew("new");
// 	lst -> next = node1;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = NULL;

// 	ft_lstadd_back(&lst, new);
// 	while(lst != NULL)
// 	{
// 		printf("%s\n", lst -> content);
// 		lst = lst -> next;
// 	}
// }
