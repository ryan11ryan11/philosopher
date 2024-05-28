/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:28 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/11 16:33:08 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// void	f(void *content)
// {
// 	char *str = (char *)content;
// 	if (str && str[0])
// 	{
// 	    str[0] = ft_toupper(str[0]);
// 	}
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

// 	ft_lstiter(lst, f);

// 	while(lst != NULL)
// 	{
// 		printf("%s\n", lst -> content);
// 		lst = lst -> next;
// 	}
// }
