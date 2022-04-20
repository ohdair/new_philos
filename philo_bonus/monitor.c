/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:17:22 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 11:50:20 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	someone_dead(t_philo *philo)
{
	sem_wait(philo->data->semapho->end_line);
	printf("\e[1;31m%lldms\t\e[0m\e[7;31m|\e[0m\e[1;31m  %d died 💀 !\e[0m\n", \
	get_time() - philo->data->create_date, philo->n + 1);
	philo->data->finish = 1;
	free_all(philo->data);
	exit(1);
}

void	*is_full(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	while (42)
	{
		if (d->eat_finish >= d->num_of_philos)
		{
			sem_wait(d->semapho->end_line);
			free_all(d);
			exit(1);
		}
		usleep(1000);
	}
}

void	*monitor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (42)
	{
		sem_wait(p->data->semapho->handle);
		if (get_time() >= p->death_time)
			someone_dead(p);
		sem_post(p->data->semapho->handle);
		usleep(100);
	}
}
