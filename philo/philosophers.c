/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:51:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*routine(void	*philosopher_void)
{
	t_philosopher	*philosopher;

	philosopher = philosopher_void;
	printf("id: %i\n", philosopher->id);
}

t_philosopher	*create_philosopher(int id, t_forks forks)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->forks = forks;
	if (pthread_create(&philosopher->thread, NULL, &routine, philosopher)) {
		printf("Error creating thread\n"); // TODO
	}
	return (philosopher);
}

t_list	*create_philosophers(int amount)
{
	int		i;
	t_list	*philosophers;
	t_forks	forks;

	i = 0;
	philosophers = NULL;
	while (i < amount)
	{
		forks.left = 0;
		forks.right = 1;
		ft_lstadd_back(&philosophers, ft_lstnew(create_philosopher(i, forks)));
		i++;
	}
	return (philosophers);
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

void	free_philosophers(t_list **philosophers)
{
	ft_lstclear(philosophers, &free);
	free(*philosophers);
}

void	philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int number_of_times_each_philosopher_must_eat
)
{
	t_list	*philosophers;

	philosophers = create_philosophers(number_of_philosophers);
	wait_philosophers(philosophers);
	free_philosophers(&philosophers);
}
