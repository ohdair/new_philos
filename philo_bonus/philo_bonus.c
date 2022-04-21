/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:42:40 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 13:45:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_data *p)
{
	kill_philo(p, p->num_of_philos);
	destroy_semaphore(p);
	free_malloc(p);
}

int	main(int argc, char **argv)
{
	t_data			*p;

	p = (t_data *)malloc(sizeof(t_data));
	if (!p)
		return (ft_error(FAIL_MALLOC));
	if (!parsing_argv(argc, argv, p))
	{
		free(p);
		return (1);
	}
	if (!philo_info_init(p))
		return (free_malloc(p));
	// free_all(p);
	return (0);
}
