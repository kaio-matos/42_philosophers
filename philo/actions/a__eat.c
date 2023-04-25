/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:27 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/24 20:20:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__eat(t_philosopher_routine *args)
{
	log_eating(args->philosopher, args->simulation);
	mssleep_checking_death(args,  args->philosopher->time_to_eat);
	args->philosopher->times_eaten++;
}
