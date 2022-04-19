/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:17:22 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/19 11:14:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	someone_dead(t_philo *philo)
{
	sem_wait(philo->data->semapho->end_line);
	printf("\e[1;31m%lldms\t\e[0m\e[7;31m|\e[0m\e[1;31m  %d died 💀 !\e[0m\n", \
	get_time() - philo->data->create_date, philo->n + 1);
	philo->data->finish = 1;
	sem_post(philo->data->semapho->forks);
	sem_post(philo->data->semapho->forks);
	sem_post(philo->data->semapho->end_line);
}

static int	observer_of_death(t_data *data)
{
	int	everyone_full;
	int	somone_dead;
	int	i;

	everyone_full = 0;
	i = -1;
	while (++i < data->num_of_philos)
	{
		sem_wait(data->semapho->handle);
		everyone_full = (data->eat_finish >= data->num_of_philos);
		somone_dead = (get_time() >= data->philos[i].death_time);
		sem_post(data->semapho->handle);
		if (somone_dead)
			break ;
	}
	if (somone_dead)
		someone_dead(&data->philos[i]);
	else if (everyone_full)
	{
		sem_wait(data->semapho->handle);
		data->finish = 1;
		sem_post(data->semapho->handle);
	}
	return (everyone_full || somone_dead);
}

void	*monitor(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	while (42)
	{
		if (observer_of_death(d))
		{
			return (NULL);
		}
		usleep(100);
	}
}
