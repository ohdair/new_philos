/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:45:08 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 11:14:46 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_thinking(t_philo *p)
{
	print_state(p, p->n, PHILO_THINKING);
	psleep(1);
}

static void	philo_pickup_forks(t_philo *p)
{
	// sem_wait(p->data->semapho->forks_lock);
	sem_wait(p->data->semapho->forks);
	print_state(p, p->n, PICKUP_LFORK);
	sem_wait(p->data->semapho->forks);
	print_state(p, p->n, PICKUP_RFORK);
}

static void	philo_eating(t_philo *p)
{
	sem_wait(p->data->semapho->handle);
	p->death_time = get_time() + p->data->time_to_die;
	sem_post(p->data->semapho->handle);
	print_state(p, p->n, PHILO_EATING);
	psleep(p->data->time_to_eat);
	sem_wait(p->data->semapho->handle);
	p->num_of_eat++;
	if (p->num_of_eat == p->data->num_of_must_eat)
		p->data->eat_finish++;
	sem_post(p->data->semapho->handle);
	sem_post(p->data->semapho->forks);
	sem_post(p->data->semapho->forks);
	// sem_post(p->data->semapho->forks_lock);
}

static void	philo_sleep(t_philo *p)
{
	print_state(p, p->n, PHILO_SLEEP);
	psleep(p->data->time_to_sleep);
}

void	*routine(void *philo)
{
	t_philo		*p;
	pthread_t	manager;

	p = (t_philo *)philo;
	pthread_create(&manager, NULL, monitor, p);
	pthread_detach(manager);
	if (p->n % 2 == 0)
		psleep(1);
	while (42)
	{
		philo_pickup_forks(p);
		philo_eating(p);
		philo_sleep(p);
		philo_thinking(p);
	}
}
