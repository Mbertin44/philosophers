/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:52 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/23 09:14:23 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
./philo 50 510 250 250 -- Un philo meurt alors qu'il devrait pas + data race
./philo 4 510 250 250 -- datarace
hardcode pour 1 philo
essayer de placer un usleep entre chaque création de philo au lieu des paires et impair
*/

void	*routine(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	pthread_mutex_lock(&philo->data->sleep_mutex);
	pthread_mutex_unlock(&philo->data->sleep_mutex);
	if (philo->id % 2 == 0)
		usleep(15000);
	while (check_dead(philo) == FALSE)
	{
		eating(philo);
		sleeping(philo);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	t_vault	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->id - 1]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&data->fork[philo->id % philo->data->nbr_philo]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&data->time_mutex);
	philo->time_last_eat = get_actual_time(data) - data->start_time_ms;
	pthread_mutex_unlock(&data->time_mutex);
	fixed_usleep(data->time_eat, philo);
	pthread_mutex_unlock(&data->fork[philo->id - 1]);
	pthread_mutex_unlock(&data->fork[philo->id % philo->data->nbr_philo]);
	if (philo->data->argc == 6)
	{
		pthread_mutex_lock(&data->death_mutex);
		philo->nbr_time_ate++;
		pthread_mutex_unlock(&data->death_mutex);
	}
	pthread_mutex_unlock(&data->fork[philo->id - 1]);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	fixed_usleep(philo->data->time_sleep, philo);
}

/*
	Pour déterminer si mon philo est mort ou non je peux récupérer en
	milliseconde le temps que ca lui a pris pour manger. le calcul est :
	TEMPS ACTUEL - DERNIERE FOIS QU'IL A MANGE.
	Maintenant que j'ai le temps que ca lui a pris pour manger,	IF le temps pris
	pour manger est supérieur au temps pour mourir alors mon philo est mort.
*/
bool	philo_is_alive(t_vault *data, int i, long int actual_time)
{
	long int	time_he_eat;

	while (1)
	{
		if (data->death == TRUE)
			return (false);
		actual_time = get_actual_time(data) - data->start_time_ms;
		pthread_mutex_lock(&data->time_mutex);
		time_he_eat = actual_time - data->philo[i].time_last_eat;
		pthread_mutex_unlock(&data->time_mutex);
		if (philo_is_full(data, i) == false)
			return (false);
		if (check_dead(&data->philo[i]) == TRUE || time_he_eat > data->time_die)
		{
			data->death = TRUE;
			print_dead(&data->philo[i]);
			return (false);
		}
		i++;
		if (i == data->nbr_philo)
			i = 0;
	}
	return (true);
}

bool	philo_is_full(t_vault *data, int i)
{
	if (data->argc == 6 && data->philo[i].nbr_time_ate
		>= data->nbr_time_eat && data->philo[i].full == FALSE)
	{
		data->philo[i].full = TRUE;
		data->nbr_philo_full++;
		if (data->nbr_philo_full == data->nbr_philo)
			return (false);
	}
	return (true);
}

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->death == TRUE)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (FALSE);
}
