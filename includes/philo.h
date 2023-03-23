/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/23 09:15:12 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

					/***** DEFINES *****/
# define TRUE 0
# define FALSE 1
# define ALIVE 0
# define DEAD 1
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5

					/***** STRUTURES *****/

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				nbr_time_ate;
	long			time_last_eat;
	int				full;
	struct s_vault	*data;
}	t_philo;

typedef struct s_vault
{
	int				argc;
	char			**argv;
	int				error;
	int				nbr_philo;
	int				nbr_philo_full;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
	int				status;
	int				death;
	long int		start_time_ms;
	long int		current_time_ms;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	sleep_mutex;
	struct timeval	start_time;
	struct timeval	current_time;
	t_philo			philo[200];
}	t_vault;

					/***** FONCTIONS *****/

/***** parsing.c *****/
bool		parsing(t_vault *data);
bool		check_argc(t_vault *data);
bool		check_param_is_digit(t_vault *data);
bool		check_param_len(t_vault *data);
void		check_param_value(t_vault *data);

/***** utils.c *****/
void		param_to_int(t_vault *data);
void		print_status(t_philo *philo, char *str);
void		print_dead(t_philo *philo);
bool		error_management(t_vault *data);
void		fixed_usleep(int time_to_sleep, t_philo *philo);

/***** init_and_stop.c *****/
void		init_data(t_vault *data, t_philo *philo, int argc, char **argv);
bool		init_philo(t_vault *data);
void		kill_them_all(t_vault *data);

/***** get_time.c *****/
void		get_start_time(t_vault *data);
long int	get_actual_time(t_vault *data);

/***** routine.c *****/
void		*routine(void *temp);
bool		philo_is_alive(t_vault *data, int i, long int actual_time);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
bool		philo_is_full(t_vault *data, int i);
bool		check_dead(t_philo *philo);

#endif