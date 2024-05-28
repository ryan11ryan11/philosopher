/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:33:48 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:42:27 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*tmp;

	tmp = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		newnode = ft_lstnew(f(lst -> content));
		if (!newnode)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, newnode);
		lst = lst -> next;
	}
	return (tmp);
}

// void	*f(void *content)
// {
// 	char	*txt = "dd";
// 	content = txt;
// 	return (content);
// }

// void	*del(void *content)
// {
// 	free(content);
// 	return (content);
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
// 	node3 -> next = new;
// 	new -> next = NULL;

// 	ft_lstmap(lst, f, (void *)del);

// 	t_list	*new_list;

// 	new_list = ft_lstmap(lst, f, (void *)del);

// 	while(lst != NULL)
// 	{
// 		printf("old list :: %s\n", lst -> content);
// 		lst = lst -> next;
// 	}

// 	while(new_list != NULL)
// 	{
// 		printf("new list :: %s\n", new_list -> content);
// 		new_list = new_list -> next;
// 	}
// }
