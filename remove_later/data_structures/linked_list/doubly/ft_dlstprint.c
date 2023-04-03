/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:08:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:07:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstnprint(t_dlist *list)
{
	if (!list)
	{
		ft_printf("{ (nil) }\n");
		return ;
	}
	ft_printf(
		"{ address: %p, content: %i, prev: %p, next: %p }\n",
		list,
		*(int*)list->content,
		list->prev,
		list->next
		);
}

void	ft_dlstprint(t_dlist *list)
{
	t_dlist	*temp;

	if (!list)
	{
		ft_dlstnprint(list);
		return ;
	}
	temp = ft_dlstfirst(list);
	while (temp)
	{
		ft_dlstnprint(temp);
		temp = temp->next;
	}
}
