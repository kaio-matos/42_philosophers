/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:23 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/04 20:11:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	create_philosopher(int id, t_forks forks)
{
	t_philosopher	philosopher;

	philosopher.id = id;
	philosopher.forks = forks;
	return (philosopher);
}

t_philosopher	*create_philosophers(int amount)
{
	int				i;
	t_philosopher	*philosophers;
	t_forks			forks;

	i = 0;
	philosophers = malloc(amount * sizeof(t_philosopher));
	while (i < amount)
	{
		forks.left = 0;
		forks.right = 0;
		philosophers[i] = create_philosopher(i, forks);
		i++;
	}
	return (philosophers);
}

void	philosophers(
	int number_of_philosophers,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int number_of_times_each_philosopher_must_eat
)
{
	t_philosopher	*philosophers;
	int i = 0;

	philosophers = create_philosophers(number_of_philosophers);
	while (i < number_of_philosophers)
	{
		printf("id: %i, forks.left: %i, forks.right: %i\n", philosophers[i].id, philosophers[i].forks.left, philosophers[i].forks.right);
		i++;
	}
	free(philosophers);
}
