/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:32:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:00:09 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*create_philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int times_to_eat
)
{
	int		i;
	t_list	*philosophers;

	i = 0;
	philosophers = NULL;
	while (i < number_of_philosophers)
	{
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(
			i + 1,
			time_to_die,
			time_to_eat,
			time_to_sleep,
			times_to_eat
		)));
		i++;
	}
	return (philosophers);
}

void	free_philosophers(t_list **philosophers)
{
	ft_lstclear(philosophers, &free);
	free(*philosophers);
}

void	wait_philosophers(t_list *philosophers)
{
	while (philosophers)
	{
		if (pthread_join(get_philosopher(philosophers)->thread, NULL))
			printf("Error waiting thread\n"); // TODO
		philosophers = philosophers->next;
	}
}
