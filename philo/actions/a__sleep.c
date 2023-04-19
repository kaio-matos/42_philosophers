/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:51 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/18 21:18:45 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__sleep(t_philosopher_routine *args)
{
	log_sleeping(args->philosopher);
	mssleep_checking_death(args, args->philosopher->time_to_sleep);
}
