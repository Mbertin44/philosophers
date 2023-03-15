/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:52 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/15 16:26:36 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (philo_is_alive(philo) == true)
	{
		eat(philo);
		// dormir;
		// penser;
	}
	return (NULL);
}

/*
	Pour déterminer si mon philo est mort ou non je peux récupérer en
	milliseconde le temps que ca lui a pris pour manger. le calcul est :
	TEMPS ACTUEL - DERNIERE FOIS QU'IL A MANGE.
	Maintenant que j'ai le temps que ca lui a pris pour manger,	IF le temps pris
	pour manger est supérieur au temps pour mourir alors mon philo est mort.
*/
bool	philo_is_alive(t_philo *philo)
{
	long int	actual_time;
	long int	time_to_eat;

	if (philo->data->death == TRUE)
		return (false);
	actual_time = get_actual_time(philo->data);
	time_to_eat = actual_time - philo->time_last_eat;
	if (philo->data->death == TRUE || time_to_eat > philo->data->time_die)
	{
		philo->data->death = TRUE;
		printf("%ld %d died\n", actual_time, philo->id);
		return (false);
	}
	return (true);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d has taken a fork\n", get_actual_time(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->nbr_philo]);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d has taken a fork\n", get_actual_time(philo->data), philo->id);
	printf("%ld %d is eating\n", get_actual_time(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	fixed_usleep(philo->data->time_eat, philo->data);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->fork[philo->id % philo->data->nbr_philo]);
	if (philo->data->argc == 6)
		philo->nbr_time_ate++;
}

// void	eat(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->data->forks[philo->id]);
//     pthread_mutex_lock(&philo->data->forks[(philo->id + 1) % philo->data->nbr_philo]);
//     pthread_mutex_lock(&philo->data->print_mutex);
//     printf("%ld %d has taken the fork %d\n", get_actual_time(philo->data), philo->id, philo->id);
//     printf("%ld %d has taken the fork %d\n", get_actual_time(philo->data), philo->id, (philo->id + 1) % philo->data->nbr_philo);
//     printf("%ld %d is eating\n", get_actual_time(philo->data), philo->id);
//     pthread_mutex_unlock(&philo->data->print_mutex);
//     fixed_usleep(philo->data->time_eat, philo->data);
//     pthread_mutex_unlock(&philo->data->forks[philo->id]);
//     pthread_mutex_unlock(&philo->data->forks[(philo->id + 1) % philo->data->nbr_philo]);
//     if (philo->data->argc == 6)
//         philo->nbr_time_ate++;
// }
