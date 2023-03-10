/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/10 15:05:33 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

					/***** DEFINES *****/
# define TRUE 1
# define FALSE 0
# define USED 0
# define UNUSED 1

					/***** STRUTURES *****/

typedef struct s_philo
{
	pthread_t		thread;
	int				id; //Le numero de mon philo
	int				f_left;// Le numero de la fourchette qu"il tien
	int				f_right;// Le numero de la fourchette qu"il tien
	int				nbr_eat; //Nombre de fois ou il mange
	long			time_last_eat; //Le dernier timestamp en milliseconde ou il à mangé. Pour verifier si mon philo est mort : Temps actuel - time_last_eat = Le temps que ca a pris pour manger
	struct s_vault	*data;
}	t_philo;

typedef struct s_vault
{
	int				argc;
	char			**argv;
	int				error;
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
	long int		start_time_ms;
	long int		current_time_ms;
	pthread_mutex_t	forks[200];
	struct timeval	start_time;
	struct timeval	current_time;
	int				death;
	t_philo			philo[200];
}	t_vault;

					/***** FONCTIONS *****/

/***** errors.c *****/
bool		error_management(t_vault *data);
bool		join_thread(t_vault *data);

/***** parsing.c *****/
bool		parsing(t_vault *data);
bool		check_argc(t_vault *data);
bool		check_param_is_digit(t_vault *data);
bool		check_param_len(t_vault *data);
void		check_param_value(t_vault *data);

/***** parsing_utils.c *****/
void		param_to_int(t_vault *data);

/***** init.c *****/
void		init_data(t_vault *data, t_philo *philo, int argc, char **argv);
bool		init_philo(t_vault *data);

/***** get_time.c *****/
void		get_start_time(t_vault *data);
long int	get_actual_time(t_vault *data);

/***** routine.c *****/
void		*routine(void *temp);
bool		philo_is_alive(t_philo *philo);

#endif