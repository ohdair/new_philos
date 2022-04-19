/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:27 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/19 11:35:05 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_time_ms	ft_atoi(const char *str)
{
	t_time_ms	nbr;

	nbr = 0;
	if (*str == '-' || *str == '+' || !str)
		return (0);
	while (*str != 0)
	{
		if (*str && '0' <= *str && *str <= '9')
		{
			nbr = (nbr * 10) + (*str++ - '0');
		}
		else
			return (0);
	}
	return (nbr);
}

int	parsing_argv(int argc, char **argv, t_data *p)
{
	if (argc != 5 && argc != 6)
		return (ft_error(WRONG_ARGC));
	p->num_of_philos = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->num_of_must_eat = 0;
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (ft_error(WRONG_ARGUMENT));
		p->num_of_must_eat = ft_atoi(argv[5]);
	}
	if (p->num_of_philos <= 0 || p->time_to_die <= 0 || p->time_to_eat <= 0 \
	|| p->time_to_sleep <= 0 || p->num_of_must_eat < 0)
		return (ft_error(WRONG_ARGUMENT));
	p->philos = ft_calloc(sizeof(t_philo), p->num_of_philos);
	if (!p->philos)
		return (ft_error(FAIL_MALLOC));
	p->semapho = ft_calloc(sizeof(t_sema), 3);
	if (!p->semapho)
		return (ft_error(FAIL_MALLOC));
	return (1);
}
