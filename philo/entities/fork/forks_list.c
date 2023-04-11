/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:31:00 by kmatos-s         ###   ########.fr       */
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

t_list	*find_fork_node_by_philosopher_id(t_list *forks, int philosopher_id)
{
	while (forks)
	{
		if (get_fork(forks)->philosopher_id == philosopher_id)
			return (forks);
		forks = forks->next;
	}
	return (NULL);
}

void	free_forks(t_list **forks)
{
	ft_lstclear(forks, &free);
	free(*forks);
}

void	print_fork(t_fork *fork)
{
	printf("\nfork {\n");
	printf("\tid \t\t %i\n", fork->id);
	printf("\tphilsopher_id \t %i\n", fork->philosopher_id);
	printf("\tis_on_table \t %i\n", fork->is_on_table);
	printf("}\n\n");
}

void	print_forks(t_list *forks)
{
	while (forks)
	{
		print_fork(get_fork(forks));
		forks = forks->next;
	}
}
