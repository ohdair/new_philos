/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:44:14 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 20:13:42 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int ERRORCODE)
{
	if (ERRORCODE == FAIL_MALLOC)
		printf("ERROR(%d) : Failed to create malloc\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGUMENT)
		printf("ERROR(%d) : Invalid argument entered\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGC)
		printf("ERROR(%d) : Invalid number of arguments\n", ERRORCODE);
	if (ERRORCODE == FAIL_MUTEX)
		printf("ERROR(%d) : Failed to create malloc\n", ERRORCODE);
	return (0);
}
