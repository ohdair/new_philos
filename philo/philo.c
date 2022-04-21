/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:42:40 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/21 12:18:41 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *p)
{
	int	i;

	i = -1;
	while (++i < p->num_of_philos)
	{
		pthread_mutex_destroy(&p->forks[i]);
		pthread_mutex_destroy(&p->philos[i].handle);
	}
	pthread_mutex_destroy(&p->end_line);
	free_malloc(p);
}

#include <string.h>
int	main(int argc, char **argv)
{
	t_data			*p;

	memset(&p, 0, sizeof(p));
	p = (t_data *)malloc(sizeof(t_data));
	if (!p)
		return (ft_error(FAIL_MALLOC));
	if (!parsing_argv(argc, argv, p))
	{
		free(p);
		return (1);
	}
	if (!philo_info_init(p))
		return (free_malloc(p));
	free_all(p);
	return (0);
}
