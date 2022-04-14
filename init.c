/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:38:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 22:11:35 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	failed_mutex(t_data *p, int i)
{
	while (i--)
	{
		pthread_mutex_destroy(&p->philos[i].handle);
		pthread_mutex_destroy(&p->forks[i]);
	}
	pthread_mutex_destroy(&p->end_line);
}

static int	mutex_init(t_data *p)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&p->end_line, NULL))
		return (ft_error(FAIL_MUTEX));
	while (++i <p ->num_of_philos)
	{
		if (pthread_mutex_init(&p->forks[i], NULL))
			break ;
		if (pthread_mutex_init(&p->philos[i].handle, NULL))
		{
			pthread_mutex_destroy(&p->forks[i]);
			break ;
		}
	}
	if (i != p->num_of_philos)
	{
		failed_mutex(p, i);
		return (ft_error(FAIL_MUTEX));
	}
	return (1);
}

int	pthread_init(t_data *p)
{
	t_time_ms	now;
	pthread_t	manager;
	int			i;

	i = -1;
	while (++i < p->num_of_philos)
	{
		now = get_time();
		p->philos[i].death_time = now + p->time_to_die;
		if (pthread_create(&p->philos[i].thread, NULL, &monitor, &p->philos[i]))
			return (0);
	}
}

int	philo_info_init(t_data *p)
{
	int	i;

	i = -1;
	p->finish = 0;
	p->create_date = get_time();
	while (++i < p->num_of_philos)
	{
		p->philos[i].n = i;
		p->philos[i].n1 = (i + 1) % p->num_of_philos;
		p->philos[i].num_of_eat = 0;
		p->philos[i].data = p;
	}
	if (!mutex_init(p))
		return (0);
	return (1);
}
