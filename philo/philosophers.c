/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 22:04:24 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/**
 * When a philosopher has finished eating, they put their forks back on the table and
 * start sleeping. Once awake, they start thinking again. The simulation stops when
 * a philosopher dies of starvation.
*/
void	*routine(void	*args_void)
{
	t_philosopher_routine	*args;
	int						i;

	args = args_void;
	while (i < 25)
	{
		a__take_fork(args->philosopher);
		a__eat(args->philosopher);
		a__sleep(args->philosopher);
		a__think(args->philosopher);
		i++;
	}
}

void	attach_forks_to_philosophers(t_list	*forks, t_list *philosophers)
{
	while (philosophers)
	{
		get_fork(forks)->philosopher_id = get_philosopher(philosophers)->id;
		forks = forks->next;
		philosophers = philosophers->next;
	}
}

t_philosopher_routine	*create_philosophers_threads(
	t_list *philosophers,
	t_list *forks,
	void *(*philosopher_routine)(void *)
)
{
	t_philosopher_routine	*philosopher_routine_args;

	philosopher_routine_args = ft_salloc(sizeof(t_philosopher_routine));
	while (philosophers)
	{
		philosopher_routine_args->philosopher = get_philosopher(philosophers);
		philosopher_routine_args->forks = forks;
		if (pthread_create(&get_philosopher(philosophers)->thread, NULL, philosopher_routine, philosopher_routine_args)) {
			printf("Error creating thread\n"); // TODO
		}
		philosophers = philosophers->next;
	}
	return (philosopher_routine_args);
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
	t_list	*forks;
	void	*trash;

	philosophers = create_philosophers(number_of_philosophers);
	forks = create_forks(number_of_philosophers);
	attach_forks_to_philosophers(forks, philosophers);

	trash = create_philosophers_threads(philosophers, forks, &routine);
	wait_philosophers(philosophers);
	free(trash);
	free_forks(&forks);
	free_philosophers(&philosophers);
}
