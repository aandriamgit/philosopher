/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:23:53 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/23 14:59:16 by aandriam         ###   ########.fr       */
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
}					t_uses;

typedef struct s_vars
{
	t_saves			saves;
	t_uses			uses;
}					t_vars;

int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
int					only_digit(char *lol);
#endif
