/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:37:04 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 11:06:24 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	kill_philo(t_data *d, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		kill(d->philos[num].pid, SIGKILL);
	return (0);
}

int	free_malloc(t_data *p)
{
	free(p->philos);
	free(p->semapho);
	free(p);
	return (1);
}

static void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	alloc = (void *)malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}

int	end_check(t_philo *p)
{
	int	result;

	sem_wait(p->data->semapho->end_line);
	result = p->data->finish;
	sem_post(p->data->semapho->end_line);
	return (result);
}
