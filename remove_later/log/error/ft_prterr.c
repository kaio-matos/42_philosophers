/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:59:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/21 20:18:26 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_prterr(char *message, ...)
{
	va_list	args;

	va_start(args, message);
	ft_vprterr(message, args);
	va_end(args);
}

void	ft_vprterr(char *message, va_list args)
{
	fdebug_log(STDERR_FILENO, SHELL_R, args);
	ft_fprintf(STDERR_FILENO, ERROR);
	fdebug_log(STDERR_FILENO, message, args);
	fdebug_log(STDERR_FILENO, SHELL_RC, args);
}
