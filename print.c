/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:44:14 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 20:13:42 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int ERRORCODE)
{
	if (ERRORCODE == FAIL_MALLOC)
		printf("ERROR(%d) : Failed to create malloc\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGUMENT)
		printf("ERROR(%d) : Invalid argument entered\n", ERRORCODE);
	if (ERRORCODE == WRONG_ARGC)
		printf("ERROR(%d) : Invalid number of arguments\n", ERRORCODE);
	if (ERRORCODE == FAIL_MUTEX)
		printf("ERROR(%d) : Failed to create mutex\n", ERRORCODE);
	if (ERRORCODE == FAIL_PTHREAD)
		printf("ERROR(%d) : Failed to create pthread\n", ERRORCODE);
	return (0);
}

void	print_state(t_philo *p, int philo, int way)
{
	unsigned int	current;

	pthread_mutex_lock(&p->data->print);
	current = get_time();
	if (p->data->finish)
		return ;
	printf("%ums\t\033[0;33m | \e[0m\033[0;97m%d\e[0m", \
	current - p->data->create_date, philo + 1);
	if (way == PICKUP_LFORK)
		printf("\033[0;32m has taken a fork 🍴 !\e[0m\n");
	if (way == PICKUP_RFORK)
		printf("\033[0;32m has taken an other fork 🍴 !\e[0m\n");
	if (way == PHILO_EATING)
		printf("\033[0;33m is eating 🍝 !\e[0m\n");
	if (way == PHILO_SLEEP)
		printf("\033[0;34m is sleeping 💤 !\e[0m\n");
	if (way == PHILO_THINKING)
		printf("\033[0;35m is thinking 🧠 !\e[0m\n");
	if (way == PHILO_DIED)
		printf("\033[1;31m died 💀 !\e[0m\n");
	pthread_mutex_unlock(&p->data->print);
}