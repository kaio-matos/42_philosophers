/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v__arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:39:44 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/03 21:17:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	v__arguments(int argc, char **argv)
{
	if (!argv[1])
		return (printf("Error missing `number_of_philosophers` argument\n"));
	if (!argv[2])
		return (printf("Error missing `time_to_die` argument\n"));
	if (!argv[3])
		return (printf("Error missing `time_to_eat` argument\n"));
	if (!argv[4])
		return (printf("Error missing `time_to_sleep` argument\n"));
	if (argv[5])
		printf("Error missing `number_of_times_each_philosopher_must_eat`\n");
	return (0);
}
