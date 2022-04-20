/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:38:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 12:30:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	run_semaphore(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		data->philos[i].n = i;
		data->philos[i].death_time = get_time() + data->time_to_die;
		data->philos[i].data = data;
		data->philos[i].num_of_eat = 0;
		data->philos[i].pid = fork();
		if (data->philos[i].pid == -1)
			return (kill_philo(data, i));
		else if (data->philos[i].pid == 0)
			routine(&data->philos[i]);
	}
	return (1);
}

int	philo_info_init(t_data *p)
{
	int	i;

	i = -1;
	p->finish = 0;
	p->eat_finish = 0;
	p->create_date = get_time();
	if (!init_semaphore(p))
		return (destroy_semaphore(p));
	if (!run_semaphore(p))
		return (0);
	return (1);
}
