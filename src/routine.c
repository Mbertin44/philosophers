/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:52 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/10 15:07:26 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *temp)
{
	t_philo	*philo;

	philo = temp;
	printf("Je suis le philo numéro %d\n", philo->id);
	while (philo_is_alive(philo) == true)
	{
		manger;
		dormir;
		penser;
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
		return (false);
	}
	return (true);
}

void	eat(t_philo philo)
{
	pthread_mutex_lock(philo.)
}
