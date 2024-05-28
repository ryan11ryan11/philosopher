/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:30 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/11 11:53:25 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp_next;

	if (!lst)
		return ;
	tmp_next = lst -> next;
	del(lst -> content);
	free(lst);
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

// 	ft_lstdelone(node1, del);

// 	while(lst != NULL)
// 	{
// 		printf("%s\n", lst -> content);
// 		lst = lst -> next;
// 	}
// }
