/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:29 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:14:08 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*current_list;
	int		counter;

	counter = 0;
	current_list = lst;
	while (current_list != NULL)
	{
		counter++;
		current_list = current_list->next;
	}
	return (counter);
}
