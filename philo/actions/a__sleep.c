/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:51 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/06 21:36:30 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__sleep(t_philosopher *philosopher)
{
	log_sleeping(philosopher);
	usleep(MILISECOND * 750);
}
