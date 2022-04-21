/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:17:22 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/21 12:24:34 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	someone_dead(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->end_line);
	i = -1;
	printf("\e[1;31m%lldms\t\e[0m\e[7;31m|\e[0m\e[1;31m  %d died 💀 !\e[0m\n", \
	get_time() - philo->data->create_date, philo->n + 1);
	philo->data->finish = 1;
	drop_forks(philo);
	pthread_mutex_unlock(&philo->data->end_line);
}

static int	observer_of_death(t_data *data)
{
	int	everyone_full;
	int	somone_dead;
	int	i;

	everyone_full = (data->num_of_must_eat != -1);
	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(&(data->philos[i].handle));
		everyone_full &= (data->num_of_must_eat <= data->philos[i].num_of_eat);
		somone_dead = (get_time() >= data->philos[i].death_time);
		pthread_mutex_unlock(&(data->philos[i].handle));
		if (somone_dead)
			break ;
	}
	if (somone_dead)
		someone_dead(&data->philos[i]);
	else if (everyone_full)
	{
		pthread_mutex_lock(&(data->end_line));
		data->finish = 1;
		pthread_mutex_unlock(&(data->end_line));
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
		usleep(1000);
	}
}
