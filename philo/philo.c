/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:23:14 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/28 15:51:57 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(t_vars vars)
{
	if (!(vars.saves.argc >= 5 && vars.saves.argc <= 6))
		return (0);
	else if ((ft_atoi(vars.saves.argv[1]) <= 0)
		|| !only_digit(vars.saves.argv[1]))
		return (0);
	else if ((ft_atoi(vars.saves.argv[2]) <= 0)
		|| !only_digit(vars.saves.argv[2]))
		return (0);
	else if ((ft_atoi(vars.saves.argv[3]) <= 0)
		|| !only_digit(vars.saves.argv[3]))
		return (0);
	else if ((ft_atoi(vars.saves.argv[4]) <= 0)
		|| !only_digit(vars.saves.argv[4]))
		return (0);
	else if (vars.saves.argv[5])
		if (!only_digit(vars.saves.argv[5]) || ft_atoi(vars.saves.argv[5]) <= 0)
			return (0);
	return (1);
}

void	saves_init(t_vars *vars, int argc, char **argv)
{
	vars->saves.argc = argc;
	vars->saves.argv = argv;
}

void	uses_init(t_vars *vars)
{
	vars->uses.philo_nb = find_philo_nb(*vars);
	vars->uses.time_to_die = ft_atoi(vars->saves.argv[2]);
	vars->uses.time_to_eat = ft_atoi(vars->saves.argv[3]);
	vars->uses.time_to_sleep = ft_atoi(vars->saves.argv[4]);
	if (vars->saves.argv[5])
		vars->uses.must_eat = ft_atoi(vars->saves.argv[5]);
}

void	lets_start_dinner(t_vars *vars)
{
	int			i;
	pthread_t	monitor;

	table_init(vars);
	philos_init(vars);
	forks_init(vars);
	i = -1;
	while (++i < vars->uses.philo_nb)
		create_routines(vars, i);
	pthread_create(&monitor, NULL, &thread_monitor, vars);
	join_them_all(*vars, monitor);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	saves_init(&vars, argc, argv);
	if (argc == 1)
		return (0);
	if (valid_args(vars))
	{
		uses_init(&vars);
		lets_start_dinner(&vars);
	}
	else
		printf("Error, please enter valid arguments\n");
	return (0);
}
