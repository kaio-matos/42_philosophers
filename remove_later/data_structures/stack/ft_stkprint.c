/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_stkhprint(t_stack *stack)
{
	if (!stack)
	{
		ft_printf("{ nil }\n");
		return ;
	}
	ft_printf("{\n");
	ft_printf("\tsize: %i\n", stack->size);
	ft_printf("\thead: ");
	ft_dlstnprint(stack->head);
	ft_printf("\tfoot: ");
	ft_dlstnprint(stack->foot);
	ft_printf("}\n");
}

void	ft_stkprint(t_stack *stack)
{
	t_dlist	*temp;

	if (!stack)
		return (ft_stkhprint(stack));
	ft_printf("{\n");
	ft_printf("\tsize: %i\n", stack->size);
	temp = stack->head;
	if (!temp)
	{
		ft_printf("\tstack: []\n");
		ft_printf("}\n");
		return ;
	}
	ft_printf("\tstack: [\n");
	while (temp)
	{
		ft_printf("\t\t");
		ft_dlstnprint(temp);
		temp = temp->prev;
	}
	ft_printf("\t]\n");
	ft_printf("}\n");
}
