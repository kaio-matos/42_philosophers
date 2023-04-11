/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:19:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/10 20:20:57 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	debug(const char *str, ...)
{
	int		printed;
	va_list	args;

	if (!VERBOSE)
		return (0);
	va_start(args, str);
	printed = vprintf(str, args);
	va_end(args);
	return (printed);
}
