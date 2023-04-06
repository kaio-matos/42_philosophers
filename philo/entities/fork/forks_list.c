/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 20:36:57 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*create_forks(int number_of_forks)
{
	int		i;
	t_list	*forks;

	i = 0;
	forks = NULL;
	while (i < number_of_forks)
	{
		ft_lstadd_back(&forks, ft_lstnew(create_fork(i + 1, -1)));
		i++;
	}
	return (forks);
}

void	free_forks(t_list **forks)
{
	ft_lstclear(forks, &free);
	free(*forks);
}

void	print_forks(t_list *forks)
{
	while (forks)
	{
		printf("\nfork {\n");
		printf("   id			%i\n", get_fork(forks)->id);
		printf("   philsopher_id	%i\n", get_fork(forks)->philosopher_id);
		printf("}\n\n");
		forks = forks->next;
	}
}
