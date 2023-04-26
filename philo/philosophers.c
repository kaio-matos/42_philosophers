/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 19:37:53 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	attach_forks_to_philosophers(t_dlist *forks, t_list *philosophers);
static void	print_args(t_arguments args);

void	philosophers(t_arguments args)
{
	t_list			*philosophers;
	t_dlist			*forks;
	pthread_t		*observer;
	t_simulation	*simulation;

	observer = ft_salloc(sizeof(pthread_t));
	simulation = create_simulation();
	philosophers = create_philosophers(
			args.number_of_philosophers,
			args.time_to_die,
			args.time_to_eat,
			args.time_to_sleep,
			args.number_of_times_each_philosopher_must_eat
			);
	forks = create_forks(args.number_of_philosophers);
	attach_forks_to_philosophers(forks, philosophers);
	print_args(args);
	th__create_observer(philosophers, simulation, observer);
	th__create_philosophers_threads(philosophers,
		forks, simulation,
		&th_philosopher_routine
		);
	wait_philosophers(philosophers);
	if (pthread_join(*observer, NULL))
		printf("Error waiting thread\n");
	free_simulation(simulation);
	free(observer);
	free_forks(&forks);
	free_philosophers(&philosophers);
}

static void	attach_forks_to_philosophers(t_dlist *forks, t_list *philosophers)
{
	while (philosophers)
	{
		get_fork(forks)->philosopher_id = get_philosopher(philosophers)->id;
		forks = forks->next;
		philosophers = philosophers->next;
	}
}

static void	print_args(t_arguments args)
{
	printf("\ntime_to_die\t\t\t\t\t%i\n", args.time_to_die);
	printf("time_to_eat\t\t\t\t\t%i\n", args.time_to_eat);
	printf("time_to_sleep\t\t\t\t\t%i\n", args.time_to_sleep);
	printf(
		"number_of_times_each_philosopher_must_eat\t%i\n\n",
		args.number_of_times_each_philosopher_must_eat
		);
	printf("%sTIME\t ID ACTION%s\n", SHELL_CB, SHELL_RC);
}
