/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/13 21:07:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_dlist	*create_forks(int number_of_forks)
{
	int		i;
	t_dlist	*forks;

	i = 0;
	forks = NULL;
	while (i < number_of_forks)
	{
		ft_dlstadd_back(&forks, ft_dlstnew(create_fork(i + 1, -1)));
		i++;
	}
	return (forks);
}

t_dlist	*find_fork_node_by_philosopher_id(t_dlist *forks, int philosopher_id)
{
	while (forks)
	{
		if (get_fork(forks)->philosopher_id == philosopher_id)
			return (forks);
		forks = forks->next;
	}
	return (NULL);
}

void	free_forks(t_dlist **forks)
{
	ft_dlstclear(forks, &free);
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

void	print_forks(t_dlist *forks)
{
	printf("forks\t\t[\n");
	while (forks)
	{
		printf("\n\tfork {\n");
		printf("\t\tid \t\t %i\n", get_fork(forks)->id);
		printf("\t\tphilsopher_id \t %i\n", get_fork(forks)->philosopher_id);
		printf("\t\tis_on_table \t %i\n", get_fork(forks)->is_on_table);
		printf("\t}\n\n");
		forks = forks->next;
	}
	printf("]\n");
}
