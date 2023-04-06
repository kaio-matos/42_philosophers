/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:18:08 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/05 21:40:48 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	*create_philosopher(
	int id,
	t_forks forks,
	void *(*philosopher_routine)(void *)
)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->forks = forks;
	if (pthread_create(&philosopher->thread, NULL, philosopher_routine, philosopher)) {
		printf("Error creating thread\n"); // TODO
	}
	return (philosopher);
}

t_philosopher	*get_philosopher(t_list *node)
{
	return ((t_philosopher	*)node->content);
}
