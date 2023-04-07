/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:27 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 21:36:33 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__eat(t_philosopher *philosopher)
{
	log_taken_fork(philosopher);
	log_eating(philosopher);
	usleep(MILISECOND * 1000);
}
