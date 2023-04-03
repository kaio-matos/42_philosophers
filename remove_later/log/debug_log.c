/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:42:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/21 20:18:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	debug_log(const char *str, ...)
{
	int		printed;
	va_list	args;

	if (!VERBOSE)
		return (0);
	va_start(args, str);
	printed = ft_vprintf(str, args);
	va_end(args);
	return (printed);
}

int	fdebug_log(int fd, const char *str, va_list args)
{
	int		printed;

	if (!VERBOSE)
		return (0);
	printed = ft_vfprintf(fd, str, args);
	return (printed);
}
