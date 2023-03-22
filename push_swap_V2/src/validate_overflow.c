/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:31 by jfrontel          #+#    #+#             */
/*   Updated: 2023/03/16 17:16:34 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_split(char **array_arg, int i)
{
	while (i >= 0)
	{
		free(array_arg[i]);
		i--;
	}
	free(array_arg);
	return ;
}

int	ft_overflow_in_one_arg(char **av, t_data *dat)
{
	char		**array_arg;
	int			i;
	long long	overflow;

	i = 0;
	array_arg = ft_split(av[1], ' ');
	while (i < dat->len_a)
	{
		overflow = ft_atoi(array_arg[i]);
		if (overflow < INT_MIN || overflow > INT_MAX)
		{
			ft_free_split(array_arg, ft_count_array(array_arg));
			return (0);
		}
		i++;
	}
	ft_free_split(array_arg, i);
	return (1);
}

int	ft_overflow(int ac, char **av, t_data *dat)
{
	int			i;
	long long	overflow;

	i = 0;
	if (ac == 2 && ft_strchr(av[1], ' ') != 0)
	{
		if (ft_overflow_in_one_arg(av, dat) == 0)
			return (0);
		else
			return (1);
	}
	else if (ac > 1 && ft_strchr(av[1], ' ') == 0)
	{
		i = 0;
		while (i < ac - 1)
		{
			overflow = ft_atoi(av[i + 1]);
			if (overflow < INT_MIN || overflow > INT_MAX)
				return (0);
			i++;
		}
	}
	return (1);
}
