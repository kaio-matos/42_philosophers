/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 21:45:21 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/**
 * When a philosopher has finished eating, they put their forks back on the table and
 * start sleeping. Once awake, they start thinking again. The simulation stops when
 * a philosopher dies of starvation.
*/
void	*routine(void	*philosopher_void)
{
	t_philosopher	*philosopher;
	int				i;

	philosopher = philosopher_void;
	while (i < 25)
	{
		a__take_fork(philosopher);
		a__eat(philosopher);
		a__sleep(philosopher);
		a__think(philosopher);
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
	wait_philosophers(philosophers);
	free_forks(&forks);
	free_philosophers(&philosophers);
}
