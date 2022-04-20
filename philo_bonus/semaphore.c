/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:35 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/20 11:40:43 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	unlink_semaphore(void)
{
	sem_unlink("/forks");
	sem_unlink("/forks_lock");
	sem_unlink("/is_end_lock");
	sem_unlink("/full_philos");
}

static void	close_semaphore(t_data *data)
{
	sem_close(data->semapho->forks);
	sem_close(data->semapho->forks_lock);
	sem_close(data->semapho->end_line);
	sem_close(data->semapho->handle);
}

int	destroy_semaphore(t_data *data)
{
	close_semaphore(data);
	unlink_semaphore();
	return (0);
}

// Assuming all the processes are owned by the same user, a mode of 0600 (S_IRUSR | S_IWUSR)
int	init_semaphore(t_data *data)
{
	sem_t	*ret;

	unlink_semaphore();
	ret = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, data->num_of_philos);
	if (ret == SEM_FAILED)
		return (ft_error(FAIL_SEMA));
	ret = data->semapho->forks;
	ret = sem_open("/forks_lock", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (ret == SEM_FAILED)
		return (ft_error(FAIL_SEMA));
	ret = data->semapho->forks_lock;
	ret = sem_open("/handle", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (ret == SEM_FAILED)
		return (ft_error(FAIL_SEMA));
	ret = data->semapho->handle;
	ret = sem_open("/end_line", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (ret == SEM_FAILED)
		return (ft_error(FAIL_SEMA));
	ret = data->semapho->end_line;
	return (1);
}
