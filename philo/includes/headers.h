/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:08:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/04/10 19:28:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define SHELL_BK "\033[0;30m"
# define SHELL_R "\033[0;31m"
# define SHELL_G "\033[0;32m"
# define SHELL_Y "\033[0;33m"
# define SHELL_B "\033[0;34m"
# define SHELL_P "\033[0;35m"
# define SHELL_C "\033[0;36m"
# define SHELL_W "\033[0;37m"

/* Bold */
# define SHELL_BKB "\033[1;30m"
# define SHELL_RB "\033[1;31m"
# define SHELL_GB "\033[1;32m"
# define SHELL_YB "\033[1;33m"
# define SHELL_BB "\033[1;34m"
# define SHELL_PB "\033[1;35m"
# define SHELL_CB "\033[1;36m"
# define SHELL_WB "\033[1;37m"

/* Reset Color */
# define SHELL_RC "\033[0m"

#endif
