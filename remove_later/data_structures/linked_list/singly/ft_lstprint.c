/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:08:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:07:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstnprint(t_list *list)
{
	if (!list)
	{
		ft_printf("{ (nil) }\n");
		return ;
	}
	ft_printf(
		"{ address: %p, content: %i, next: %p }\n",
		list,
		*(int*)list->content,
		list->next
		);
}

void	ft_lstprint(t_list *list)
{
	t_list	*temp;

	if (!list)
	{
		ft_lstnprint(list);
		return ;
	}
	temp = list;
	while (temp)
	{
		ft_lstnprint(temp);
		temp = temp->next;
	}
}
