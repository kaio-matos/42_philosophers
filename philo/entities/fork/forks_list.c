/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:20:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 21:27:40 by kmatos-s         ###   ########.fr       */
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

static void	free_fork(void *void_fork)
{
	t_fork	*fork;

	fork = void_fork;
	pthread_mutex_destroy(fork->mutex);
	free(fork->mutex);
	free(fork);
}

void	free_forks(t_dlist **forks)
{
	ft_dlstclear(forks, &free_fork);
	free(*forks);
}
