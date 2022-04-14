/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:42:40 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 20:12:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			*p;

	p = (t_data *)malloc(sizeof(t_data));
	if (!p)
		return (ft_error(FAIL_MALLOC));
	if (!parsing_argv(argc, argv, p))
	{
		free(p);
		return (1);
	}
	if (!philo_info_init)
		return (free_malloc(p));
	return (0);
}
