/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:54:40 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/11 13:41:26 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	while ((*lst))
	{
		del((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list	*lst;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*new;

// 	char	*content_lst;
// 	char	*content_node1;
// 	char	*content_node2;
// 	char	*content_node3;
// 	char	*content_new;

// 	content_lst = ft_strdup("lst");
// 	content_node1 = ft_strdup("node1");
// 	content_node2 = ft_strdup("node2");
// 	content_node3 = ft_strdup("node3");
// 	content_new = ft_strdup("new");

// 	lst = ft_lstnew(content_lst);
// 	node1 = ft_lstnew(content_node1);
// 	node2 = ft_lstnew(content_node2);
// 	node3 = ft_lstnew(content_node3);
// 	new = ft_lstnew(content_new);
// 	lst -> next = node1;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = new;
// 	new -> next = NULL;

// 	ft_lstclear(&node3, del);

// 	while(lst != NULL)
// 	{
// 		printf("%s\n", lst -> content);
// 		lst = lst -> next;
// 	}
// }
