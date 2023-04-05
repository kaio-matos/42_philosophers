/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:00:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:14:08 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_list;

	if (!lst)
		return (NULL);
	current_list = lst;
	while (current_list->next != NULL)
		current_list = current_list->next;
	return (current_list);
}
