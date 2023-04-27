/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:18:08 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/26 21:29:59 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	*create_philosopher(int id, t_arguments args)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->time_to_die = args.time_to_die;
	philosopher->time_to_eat = args.time_to_eat;
	philosopher->time_to_sleep = args.time_to_sleep;
	philosopher->times_to_eat = args.number_of_times_each_philosopher_must_eat;
	philosopher->times_eaten = 0;
	philosopher->last_meal_ms = -1;
	return (philosopher);
}

int	is_philosopher_dead(t_philosopher *philosopher, t_simulation *simulation)
{
	if (philosopher->last_meal_ms == -1)
		return (FALSE);
	if (philosopher->times_eaten == philosopher->times_to_eat)
		return (FALSE);
	if (
		get_time_offset_ms(philosopher->last_meal_ms) > philosopher->time_to_die
	)
	{
		simulation->is_simulation_running = FALSE;
		usleep(1000);
		log_death(philosopher, simulation);
		return (TRUE);
	}
	return (FALSE);
}

t_philosopher	*get_philosopher(t_list *node)
{
	return ((t_philosopher *)node->content);
}
