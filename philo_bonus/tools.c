/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:50:53 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/19 11:16:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	psleep(int time)
{
	t_time_ms	start;
	t_time_ms	cur;

	start = get_time();
	while (1)
	{
		cur = get_time();
		if (start + time <= cur)
		{
			break ;
		}
		usleep(1000);
	}
}

void	end_flag(t_data *p)
{
	sem_wait(p->semapho->end_line);
	p->finish = 1;
	sem_post(p->semapho->end_line);
}

t_time_ms	get_time(void)
{
	struct timeval	time;
	t_time_ms		ret;

	gettimeofday(&time, NULL);
	ret = (t_time_ms)time.tv_sec * 1000;
	ret += time.tv_usec / 1000;
	return (ret);
}
