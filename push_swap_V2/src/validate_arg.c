/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:33:08 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/24 16:33:11 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_repeated_nb(t_data *dat)
{
	int	i;
	int	j;

	i = 0;
	while (i < dat->len_a - 1)
	{
		j = i + 1;
		while (j < dat->len_a)
		{
			if (dat->sk_a[i].nb == dat->sk_a[j].nb)
				return (0);
		j++;
		}
	i++;
	}
	return (1);
}

int	ft_count_array(char **array_arg)
{
	int	z;

	z = 0;
	while (array_arg[z])
		z++;
	return (z);
}

int	ft_argument_are_nb_1(char **av)
{
	char	**array_arg;
	int		j;
	int		i;

	i = 0;
	array_arg = ft_split(av[1], ' ');
	while (array_arg[i])
	{
		j = 0;
		if (array_arg[i][0] == '+' || array_arg[i][0] == '-')
			j++;
		while (array_arg[i][j] != '\0')
		{
			if (array_arg[i][j] < '0' || array_arg[i][j] > '9')
			{
				ft_free_split(array_arg, ft_count_array(array_arg));
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free_split(array_arg, i);
	return (1);
}

int	ft_argument_are_nb_2(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 1 && ft_strchr(av[1], ' ') == 0)
	{
		while (av[i])
		{
			j = 0;
			if (av[i][0] == '+' || av[i][0] == '-')
					j++;
			while (av[i][j] != '\0')
			{
				if (av[i][j] < 48 || av[i][j] > 57)
					return (0);
			j++;
			}
		i++;
		}
	}
	return (1);
}

int	ft_validate_av(int ac, char **av, t_data *dat)
{
	if (ft_argument_are_nb_1(av) == 0 || ft_argument_are_nb_2 (ac, av) == 0)
		return (-1);
	if (ac == 2 && ft_strchr(av[1], ' ') != 0)
		ft_numbers_in_one_argument(av, dat);
	if (ac > 1 && ft_strchr(av[1], ' ') == 0)
		ft_numbers_in_many_argument(ac, av, dat);
	if (ft_repeated_nb(dat) == 0 || ft_overflow(ac, av, dat) == 0)
	{
		free(dat->sk_a);
		free(dat->sk_b);
		free(dat->aux);
		return (-1);
	}
	return (0);
}
