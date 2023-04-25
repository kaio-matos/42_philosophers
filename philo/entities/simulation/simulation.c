/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:54:30 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/24 20:59:08 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_simulation	*create_simulation(void)
{
	t_simulation	*simulation;

	simulation = ft_salloc(sizeof(t_simulation));
	simulation->is_simulation_running = TRUE;
	simulation->mutex = ft_salloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(simulation->mutex, NULL);
	return (simulation);
}

void	free_simulation(t_simulation *simulation)
{
	pthread_mutex_destroy(simulation->mutex);
	free(simulation->mutex);
	free(simulation);
}
