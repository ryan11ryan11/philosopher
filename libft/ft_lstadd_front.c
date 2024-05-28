/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:09:28 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/07 15:20:02 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// int main()
// {
//     t_list *new;
// 	t_list *lst;
// 	new = (t_list *)malloc(sizeof(t_list));
// 	lst = (t_list *)malloc(sizeof(t_list));
// 	ft_lstadd_front(&lst, new);
// 	// t_list *lst;
// 	// t_list *new;
// 	// char content[] = "test";
// 	// lst = ft_lstnew(content);
// 	// new = ft_lstnew(content);
// 	// ft_lstadd_front(&lst, new);
// }