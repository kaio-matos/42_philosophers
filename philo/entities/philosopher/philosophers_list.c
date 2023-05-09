/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:32:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/08 21:25:09 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*create_philosophers(t_arguments args)
{
	int		i;
	t_list	*philosophers;

	i = 0;
	philosophers = NULL;
	while (i < args.number_of_philosophers)
	{
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(
					i + 1,
					args
					)));
		i++;
	}
	return (philosophers);
}

void	free_philosophers(t_list **philosophers)
{
	t_list	*philos;

	philos = *philosophers;
	while (philos)
	{
		pthread_mutex_destroy(get_philosopher(philos)->mutex);
		free(get_philosopher(philos)->mutex);
		philos = philos->next;
	}
	ft_lstclear(philosophers, &free);
	free(*philosophers);
}

int	are_philosophers_satisfied(t_list *philosophers)
{
	while (philosophers)
	{
		pthread_mutex_lock(get_philosopher(philosophers)->mutex);
		if (get_philosopher(philosophers)->times_eaten
			!= get_philosopher(philosophers)->times_to_eat)
		{
			pthread_mutex_unlock(get_philosopher(philosophers)->mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(get_philosopher(philosophers)->mutex);
		philosophers = philosophers->next;
	}
	return (TRUE);
}

void	wait_philosophers(t_list *philosophers)
{
	while (philosophers)
	{
		if (pthread_join(get_philosopher(philosophers)->thread, NULL))
			printf("Error waiting thread\n");
		philosophers = philosophers->next;
	}
}
