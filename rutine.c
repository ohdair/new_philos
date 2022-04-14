#include "philo.h"

static void philos_pickup_fork(t_philo *p)
{
    if (p->n % 2)
    {
        pthread_mutex_lock(&p->data->forks[p->n]);
        print_state(p, p->n, PICKUP_LFORK);
        pthread_mutex_lock(&p->data->forks[p->n1]);
        print_state(p, p->n1, PICKUP_RFORK);
    }
    else
    {
        pthread_mutex_lock(&p->data->forks[p->n1]);
        print_state(p, p->n1, PICKUP_RFORK);
        pthread_mutex_lock(&p->data->forks[p->n]);
        print_state(p, p->n, PICKUP_LFORK);
    }
}

static void eating(t_philo *p)
{
    pthread_mutex_lock(&p->handle);
    p->death_time = get_time() + p->data->time_to_die;
    pthread_mutex_unlock(&p->handle);
    print_state(p, p->n, PHILO_EATING);
    psleep(p->data->time_to_eat);
    pthread_mutex_lock(&p->handle);
    p->num_of_eat++;
    pthread_mutex_unlock(&p->handle);
    pthread_mutex_unlock(&p->data->forks[p->n]);
    pthread_mutex_unlock(&p->data->forks[p->n1]);
}

void    *rutine(void *philo)
{
    t_philo *p;

    p = (t_philo *)philo;
    if (p->n % 2)
        psleep(1);
    while (42)
    {

    }
}