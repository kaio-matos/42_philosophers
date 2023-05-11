/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v__arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:39:44 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/05/11 02:31:55 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_too_big(char *number, long max, char *name)
{
	if (!number)
		return (0);
	if (ft_atol(number) > max)
	{
		printf("Error: `%s` is too big\n", name);
		return (1);
	}
	return (0);
}

static int	is_valid(char *arg, char *name)
{
	if (!arg)
	{
		printf("Error: missing `%s` argument\n", name);
		return (0);
	}
	if (!ft_isstrdigit(arg))
	{
		printf("Error: invalid `%s` argument\n", name);
		return (0);
	}
	if (is_too_big(arg, MAX_INT, name))
		return (0);
	if (ft_atoi(arg) <= 0)
	{
		printf("Error: invalid `%s` argument\n", name);
		return (0);
	}
	return (1);
}

int	v__arguments(int argc, char **argv)
{
	if (argc > 6)
	{
		printf("Error: too many arguments\n");
		return (1);
	}
	if (is_too_big(argv[1], 200, "number_of_philosophers"))
		return (1);
	if (!is_valid(argv[1], "number_of_philosophers"))
		return (1);
	if (!is_valid(argv[2], "time_to_die"))
		return (1);
	if (!is_valid(argv[3], "time_to_eat"))
		return (1);
	if (!is_valid(argv[4], "time_to_sleep"))
		return (1);
	if ((argv[5] && !ft_isstrdigit(argv[5]))
		|| (argv[5] && ft_atoi(argv[5]) == 0))
		return (printf("Error: invalid `%s` argument\n",
				"number_of_times_each_philosopher_must_eat"));
	if (is_too_big(argv[5], MAX_INT, \
			"number_of_times_each_philosopher_must_eat"))
		return (1);
	return (0);
}
