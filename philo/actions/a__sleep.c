/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:51 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/17 21:07:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__sleep(t_philosopher *philosopher)
{
	log_sleeping(philosopher);
	mssleep(philosopher->time_to_sleep);
}
