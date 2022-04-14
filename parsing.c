/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:27 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 19:36:37 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	long long	si;
	long long	nbr;

	si = 1;
	nbr = 0;
	if (*str == '-' || *str == '+' || *str == 0 || !str)
		return (-1);
	while (*str != 0)
	{
		if (*str && '0' <= *str && *str <= '9')
		{
			nbr = (nbr * 10) + (*str++ - '0');
			if ((nbr > 2147483647 && si == 1))
				return (-1);
		}
		else
			return (-1);
	}
	return ((int)(nbr * si));
}

int	parsing_argv(int argc, char **argv, t_data *p)
{
	if (argc != 5 || argc != 6)
		return (ft_error(WRONG_ARGC));
	p->num_of_philos = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->num_of_must_eat = 0;
	if (argc == 6)
		p->num_of_must_eat = ft_atoi(argv[5]);
	if (p->num_of_philos <= 0 || p->time_to_die <= 0 || !ft_atoi(argv[4]) || \
	p->time_to_eat <= 0 || p->time_to_sleep <= 0 || p->num_of_must_eat < 0)
		return (ft_error(WRONG_ARGUMENT));
	p->philos = ft_calloc(sizeof(t_philo), p->num_of_philos);
	if (!p->philos)
		return (ft_error(FAIL_MALLOC));
	p->forks = ft_calloc(sizeof(pthread_mutex_t), p->num_of_philos);
	if (!p->forks)
		return (ft_error(FAIL_MALLOC));
	return (1);
}
