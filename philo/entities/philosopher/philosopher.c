/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:18:08 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 22:04:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philosopher	*create_philosopher(
	int id,
	t_forks forks
)
{
	t_philosopher	*philosopher;

	philosopher = ft_salloc(sizeof(t_philosopher));
	philosopher->id = id;
	philosopher->forks = forks;
	return (philosopher);
}

t_philosopher	*get_philosopher(t_list *node)
{
	return ((t_philosopher	*)node->content);
}
