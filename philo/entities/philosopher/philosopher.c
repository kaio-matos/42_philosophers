/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:18:08 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:00:00 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	*create_philosopher(
	int id,
	int time_to_die,
	int time_to_eat,
	int time_to_sleep,
	int times_to_eat
)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->time_to_die = time_to_die;
	philosopher->time_to_eat = time_to_eat;
	philosopher->time_to_sleep = time_to_sleep;
	philosopher->times_to_eat = times_to_eat;
	return (philosopher);
}

t_philosopher	*get_philosopher(t_list *node)
{
	return ((t_philosopher	*)node->content);
}
