/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:38:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/19 12:03:35 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	failed_pthread(t_data *p, int i, pthread_t *manager)
{
	end_flag(p);
	if (manager != NULL)
		pthread_detach(*manager);
	while (i--)
		pthread_join(p->philos[i].thread, NULL);
	ft_error(FAIL_PTHREAD);
	return (0);
}

int	destroy_semapho(t_data *p)
{
	sem_close(p->semapho->forks);
	sem_close(p->semapho->handle);
	sem_close(p->semapho->end_line);
	sem_unlink("/forks");
	sem_unlink("/handle");
	sem_unlink("/end_line");
	return (0);
}

static int	semapho_init(t_data *p)
{
	p->semapho->forks = sem_open("/forks", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, p->num_of_philos);
	p->semapho->handle = sem_open("/handle", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	p->semapho->end_line = sem_open("/end_line", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	if (!p->semapho->forks || !p->semapho->handle || !p->semapho->end_line)
		return (ft_error(FAIL_SEMA));
	return (1);
}

static int	pthread_init(t_data *p)
{
	t_time_ms	now;
	pthread_t	manager;
	int			i;

	i = -1;
	while (++i < p->num_of_philos)
	{
		now = get_time();
		p->philos[i].death_time = now + p->time_to_die;
		if (pthread_create(&p->philos[i].thread, NULL, rutine, &p->philos[i]))
			return (failed_pthread(p, i, NULL));
	}
	if (pthread_create(&manager, NULL, monitor, p))
		return (failed_pthread(p, i, NULL));
	pthread_detach(manager);
	while (i--)
		pthread_join(p->philos[i].thread, NULL);
	return (1);
}

int	philo_info_init(t_data *p)
{
	int	i;

	i = -1;
	p->finish = 0;
	p->eat_finish = 0;
	p->create_date = get_time();
	while (++i < p->num_of_philos)
	{
		p->philos[i].n = i;
		p->philos[i].n1 = (i + 1) % p->num_of_philos;
		p->philos[i].num_of_eat = 0;
		p->philos[i].data = p;
	}
	if (!semapho_init(p))
		return (destroy_semapho(p));
	if (!pthread_init(p))
		return (0);
	return (1);
}
