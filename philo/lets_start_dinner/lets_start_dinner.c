/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_start_dinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:39:20 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/24 09:05:53 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

void	table_init(t_vars *vars)
{
	vars->table.forks = malloc(sizeof(t_forks) * vars->uses.philo_nb);
	vars->table.philo = malloc(sizeof(t_philo) * vars->uses.philo_nb);
}

void	philos_init(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->uses.philo_nb)
	{
		vars->table.philo[i].died = 0;
		vars->table.philo[i].is_eating = 0;
		vars->table.philo[i].is_sleeping = 0;
		vars->table.philo[i].is_thinking = 0;
		vars->table.philo[i].forks_in_hand = 0;
		vars->table.philo[i].has_taken_a_fork = 0;
		vars->table.philo[i].uses = vars->uses;
		i++;
	}
}

void	forks_init(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->uses.philo_nb)
	{
		vars->table.forks[i].state = 0;
		i++;
	}
}

void	create_routines(t_vars *vars, int i)
{
	if (pthread_create(&vars->table.philo[i].thread_id, NULL, &thread_routine,
			(void *)&vars->table.philo[i]) != 0)
		printf("Error\n");
}

void	*thread_monitor(void *vars)
{
	return (vars);
}

void	join_them_all(t_vars vars, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < vars.uses.philo_nb)
	{
		if (pthread_join(vars.table.philo[i].thread_id, NULL) != 0)
			printf("Error\n");
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		printf("Error\n");
}
