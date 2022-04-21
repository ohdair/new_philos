/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:45:08 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/21 13:56:17 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_thinking(t_philo *p)
{
	print_state(p, p->n, PHILO_THINKING);
	psleep(1);
	return (end_check(p));
}

static int	philo_pickup_forks(t_philo *p)
{
	if (p->n % 2 == 0)
	{
		pthread_mutex_lock(&p->data->forks[p->n]);
		print_state(p, p->n, PICKUP_LFORK);
		pthread_mutex_lock(&p->data->forks[p->n1]);
		print_state(p, p->n, PICKUP_RFORK);
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->n1]);
		print_state(p, p->n, PICKUP_LFORK);
		pthread_mutex_lock(&p->data->forks[p->n]);
		print_state(p, p->n, PICKUP_RFORK);
	}
	return (end_check(p));
}

static int	philo_eating(t_philo *p)
{
	pthread_mutex_lock(&p->handle);
	p->death_time = get_time() + p->data->time_to_die;
	pthread_mutex_unlock(&p->handle);
	print_state(p, p->n, PHILO_EATING);
	pthread_mutex_lock(&p->handle);
	p->num_of_eat++;
	if (p->num_of_eat == p->data->num_of_must_eat)
		p->data->eat_finish++;
	pthread_mutex_unlock(&p->handle);
	psleep(p->data->time_to_eat);
	drop_forks(p);
	return (end_check(p));
}

static int	philo_sleep(t_philo *p)
{
	print_state(p, p->n, PHILO_SLEEP);
	psleep(p->data->time_to_sleep);
	return (end_check(p));
}

void	*rutine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->n % 2 == 0)
		psleep(2);
	while (42)
	{
		if (philo_pickup_forks(p))
		{
			drop_forks(p);
			return (NULL);
		}
		if (philo_eating(p))
			return (NULL);
		if (philo_sleep(p))
			return (NULL);
		if (philo_thinking(p))
			return (NULL);
	}
}
