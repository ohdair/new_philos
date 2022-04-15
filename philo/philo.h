/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:40:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/15 16:12:30 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define SUCCESS 0
# define WRONG_ARGC 1
# define WRONG_ARGUMENT 2
# define FAIL_MALLOC 3
# define FAIL_MUTEX 4
# define FAIL_PTHREAD 5

# define PICKUP_LFORK 1
# define PICKUP_RFORK 2
# define PHILO_EATING 3
# define PHILO_SLEEP 4
# define PHILO_THINKING 5
# define PHILO_DIED 666

typedef unsigned long long	t_time_ms;
typedef struct s_philo
{
	int				n;
	int				n1;
	int				num_of_eat;
	t_time_ms		death_time;
	pthread_t		thread;
	pthread_mutex_t	handle;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	end_line;
	t_philo			*philos;
	t_time_ms		time_of_start;
	int				finish;
	int				eat_finish;
	int				num_of_philos;
	t_time_ms		create_date;
	t_time_ms		time_to_die;
	t_time_ms		time_to_eat;
	t_time_ms		time_to_sleep;
	int				num_of_must_eat;
}	t_data;

/* print */
void			print_state(t_philo *p, int philo, int way);
int				ft_error(int ERRORCODE);

/* parsing */
int				parsing_argv(int argc, char **argv, t_data *p);

/* utils */
int				free_malloc(t_data *p);
void			*ft_calloc(size_t count, size_t size);
int				end_check(t_philo *p);

/* tools */
void			psleep(int time);
void			end_flag(t_data *p);
t_time_ms		get_time(void);
void			drop_forks(t_philo *p);

/* init */
int				philo_info_init(t_data *p);

/* rutine */
void			*rutine(void *philo);

/* monitor.c */
void			*monitor(void *data);

#endif
