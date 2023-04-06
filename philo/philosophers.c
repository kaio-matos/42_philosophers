/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/05 21:42:44 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*routine(void	*philosopher_void)
{
	t_philosopher	*philosopher;

	philosopher = philosopher_void;
	// printf("id: %i\n", philosopher->id);
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

	philosophers = create_philosophers(number_of_philosophers, &routine);
	forks = create_forks(number_of_philosophers);
	attach_forks_to_philosophers(forks, philosophers);
	print_forks(forks);
	free_forks(&forks);
	wait_philosophers(philosophers);
	free_philosophers(&philosophers);
}
