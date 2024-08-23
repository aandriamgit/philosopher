/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:23:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/23 16:41:27 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_saves
{
	int				argc;
	char			**argv;
}					t_saves;

typedef struct s_uses
{
	pthread_mutex_t	mutex;
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_uses;

typedef struct s_vars
{
	t_saves			saves;
	t_uses			uses;
}					t_vars;

int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
int					only_digit(char *lol);
int					find_philo_nb(t_vars vars);

#endif
