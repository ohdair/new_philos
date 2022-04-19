/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:44:14 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/19 11:18:57 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_error(int ERRORCODE)
{
	if (ERRORCODE == FAIL_MALLOC)
		printf("ERROR(%d) : Failed to create malloc\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGUMENT)
		printf("ERROR(%d) : Invalid argument entered\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGC)
		printf("ERROR(%d) : Invalid number of arguments\n", ERRORCODE);
	if (ERRORCODE == FAIL_SEMA)
		printf("ERROR(%d) : Failed to create semaphore\n", ERRORCODE);
	if (ERRORCODE == FAIL_PTHREAD)
		printf("ERROR(%d) : Failed to create pthread\n", ERRORCODE);
	return (0);
}

void	print_state(t_philo *p, int philo, int way)
{
	t_time_ms	current;

	sem_wait(p->data->semapho->end_line);
	if (!p->data->finish)
	{
		current = get_time();
		printf("\e[0;36m%lldms\t\e[0m\e[7;37m|\e[0m\e[0;97m  %d\e[0m", \
		current - p->data->create_date, philo + 1);
		if (way == PICKUP_LFORK)
			printf("\e[1;32m has taken a fork 🍴 !\e[0m\n");
		if (way == PICKUP_RFORK)
			printf("\e[1;32m has taken an other fork 🍴 !\e[0m\n");
		if (way == PHILO_EATING)
			printf("\e[1;33m is eating 🍝 !\e[0m\n");
		if (way == PHILO_SLEEP)
			printf("\e[1;34m is sleeping 💤 !\e[0m\n");
		if (way == PHILO_THINKING)
			printf("\e[1;35m is thinking 🧠 !\e[0m\n");
	}
	sem_post(p->data->semapho->end_line);
}
