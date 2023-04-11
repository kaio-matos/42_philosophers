/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:43 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/11 20:17:42 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__think(t_philosopher *philosopher)
{
	log_thinking(philosopher);
	// usleep(MILISECOND * 2000); // ?: figure out what time is it
}
