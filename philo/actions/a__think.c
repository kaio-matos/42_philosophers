/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a__think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:35:43 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/24 20:17:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	a__think(t_philosopher_routine *args)
{
	log_thinking(args->philosopher, args->simulation);
}
