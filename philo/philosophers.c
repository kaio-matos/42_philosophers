/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:09:24 by kmatos-s         ###   ########.fr       */
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
	long					start_time;
	t_using_forks			*using_forks;

	args = args_void;
	i = args->philosopher->times_to_eat;
	start_time = current_time_ms();
	while (i || args->philosopher->times_to_eat == -1)
	{
		if (is_philosopher_dead(args->philosopher, start_time))
			break ;
		using_forks = a__take_fork(args->philosopher, args->forks);
		if (!using_forks)
			break ;
		if (is_philosopher_dead(args->philosopher, start_time))
			break ;
		start_time = current_time_ms();
		a__eat(args->philosopher);
		a__put_forks_on_table(args->philosopher, args->forks, using_forks);
		if (is_philosopher_dead(args->philosopher, start_time))
			break ;

		a__sleep(args->philosopher);

		if (is_philosopher_dead(args->philosopher, start_time))
			break ;

		a__think(args->philosopher);

		if (is_philosopher_dead(args->philosopher, start_time))
			break ;
		i--;
	}
	free(args);
	return (NULL);
}

void	attach_forks_to_philosophers(t_dlist	*forks, t_list *philosophers)
{
	while (philosophers)
	{
		get_fork(forks)->philosopher_id = get_philosopher(philosophers)->id;
		forks = forks->next;
		philosophers = philosophers->next;
	}
}

void	create_philosophers_threads(
	t_list *philosophers,
	t_dlist *forks,
	void *(*philosopher_routine)(void *)
)
{
	t_philosopher_routine	*philosopher_routine_args;

	while (philosophers)
	{
		philosopher_routine_args = ft_salloc(sizeof(t_philosopher_routine));
		philosopher_routine_args->philosopher = get_philosopher(philosophers);
		philosopher_routine_args->forks = forks;
		debug("%sCreating thread for Philosopher: %i %s\n", SHELL_GB, philosopher_routine_args->philosopher->id, SHELL_RC);
		if (pthread_create(&get_philosopher(philosophers)->thread, NULL, philosopher_routine, philosopher_routine_args)) {
			printf("Error creating thread\n"); // TODO
		}
		philosophers = philosophers->next;
	}
}

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
	create_philosophers_threads(philosophers, forks, &routine);
	wait_philosophers(philosophers);
	free_forks(&forks);
	free_philosophers(&philosophers);
}
