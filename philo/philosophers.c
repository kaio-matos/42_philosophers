/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/24 20:58:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	attach_forks_to_philosophers(t_dlist	*forks, t_list *philosophers);

void	philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int number_of_times_each_philosopher_must_eat
)
{
	t_list			*philosophers;
	t_dlist			*forks;
	pthread_t		*observer;
	t_simulation	*simulation;

	observer = ft_salloc(sizeof(pthread_t));
	simulation = create_simulation();
	philosophers = create_philosophers(
		number_of_philosophers,
		time_to_die,
		time_to_eat,
		time_to_sleep,
		number_of_times_each_philosopher_must_eat
	);
	forks = create_forks(number_of_philosophers);
	attach_forks_to_philosophers(forks, philosophers);

	printf("\ntime_to_die\t\t\t\t\t%i\n", time_to_die);
	printf("time_to_eat\t\t\t\t\t%i\n", time_to_eat);
	printf("time_to_sleep\t\t\t\t\t%i\n", time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat\t%i\n\n", number_of_times_each_philosopher_must_eat);

	printf("%sTIME\t ID ACTION%s\n", SHELL_CB, SHELL_RC);
	th__create_observer(philosophers, simulation, observer);
	th__create_philosophers_threads(philosophers, forks, simulation, &th_philosopher_routine);
	wait_philosophers(philosophers);
	if (pthread_join(*observer, NULL))
		printf("Error waiting thread\n");
	free_simulation(simulation);
	free(observer);
	free_forks(&forks);
	free_philosophers(&philosophers);
}

static void	attach_forks_to_philosophers(t_dlist	*forks, t_list *philosophers)
{
	while (philosophers)
	{
		get_fork(forks)->philosopher_id = get_philosopher(philosophers)->id;
		forks = forks->next;
		philosophers = philosophers->next;
	}
}
