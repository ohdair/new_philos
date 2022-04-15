/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:37:04 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/15 15:54:32 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_malloc(t_data *p)
{
	free(p->forks);
	free(p->philos);
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

	pthread_mutex_lock(&p->data->end_line);
	result = p->data->finish;
	pthread_mutex_unlock(&p->data->end_line);
	return (result);
}
