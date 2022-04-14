/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:40:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/14 20:13:35 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define WRONG_ARGC 1
# define WRONG_ARGUMENT 2
# define FAIL_MALLOC 3
# define FAIL_MUTEX 4

# define PICKUP_LFORK 1
# define PICKUP_RFORK 2
# define PHILO_EATING 3
# define PHILO_SLEEP 4
# define PHILO_THINKING 5
# define PHILO_DIED 666

typedef struct s_philo
{
	int				n;
	int				n1;
	int				num_of_eat;
	unsigned int	death_time;
	pthread_t		thread;
	pthread_mutex_t	handle;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	end_line;
	t_philo			*philos;
	unsigned int	time_of_start;
	int				finish;
	int				eat_finish;
	unsigned int	create_date;
	int				num_of_philos;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
}	t_data;

/* print */
int				ft_error(int ERRORCODE);

/* parsing */
int				parsing_argv(int argc, char **argv, t_data *p);

/* utils */
unsigned int	get_time(void);
void			*ft_calloc(size_t count, size_t size);
int				free_malloc(t_data *p);

/* init */
int				philo_info_init(t_data *p);


/* 				옛날 코드 					*/

void			philo_state(t_philo *p, int philo, int way);

void			*check_death(void *arg);
void			*check_eat(void *arg);
void			psleep(int time);

/* monitor.c */
void			*monitor(void *arg);

#endif
