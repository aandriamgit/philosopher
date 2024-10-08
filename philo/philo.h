/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:23:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/28 15:53:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_saves
{
	int				argc;
	char			**argv;
}					t_saves;

typedef struct s_uses
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	unsigned long	start_time;
}					t_uses;

typedef struct s_states
{
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				has_taken_a_fork;
}					t_states;

typedef struct s_philo
{
	int				forks_in_hand;
	int				died;
	int				id;
	t_uses			uses;
	t_states		states;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_forks
{
	int				state;
}					t_forks;

typedef struct s_table
{
	t_forks			*forks;
	t_philo			*philo;
}					t_table;

typedef struct s_vars
{
	t_saves			saves;
	t_uses			uses;
	t_table			table;
}					t_vars;

int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
int					only_digit(char *lol);
int					find_philo_nb(t_vars vars);
void				table_init(t_vars *vars);
void				philos_init(t_vars *vars);
void				forks_init(t_vars *vars);
void				create_routines(t_vars *vars, int i);
void				*thread_routine(void *vars);
void				*thread_monitor(void *vars_dim);
void				join_them_all(t_vars vars, pthread_t monitor);

#endif
