/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_and_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:14:09 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/26 15:14:12 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_array(t_data *dat)
{
	int	j;
	int	i;
	int	temp;

	i = dat->len_a - 1;
	j = 0;
	while (j < i)
	{
		if (dat->aux[j].nb > dat->aux[j + 1].nb)
		{
			temp = dat->aux[j].nb;
			dat->aux[j].nb = dat->aux[j + 1].nb;
			dat->aux[j + 1].nb = temp;
			j = 0;
		}
		else
			j++;
	}
}

void	ft_sort_index(t_data *dat, int i)
{
	int	z;
	int	temp;

	z = 0;
	while (z < i)
	{
		if (dat->aux[z].index > dat->aux[z + 1].index)
		{
			temp = dat->aux[z].index;
			dat->aux[z].index = dat->aux[z + 1].index;
			dat->aux[z + 1].index = temp;
			z = 0;
		}
		else
			z++;
	}
}

void	ft_search_index(t_data *dat)
{
	int	j;
	int	i;

	i = 0;
	ft_sort_array(dat);
	while (i < dat->len_a)
	{
		j = 0;
		while (j < dat->len_a)
		{
			if (dat->sk_a[i].nb == dat->aux[j].nb)
				dat->sk_a[i].index = j + 1;
		j++;
		}
	i++;
	}
}

void	ft_numbers_in_one_argument(char **av, t_data *dat)
{
	char	**array_arg;
	int		j;
	int		i;

	i = 0;
	j = 0;
	array_arg = ft_split(av[1], ' ');
	while (array_arg[j])
		j++;
	dat->sk_a = malloc(sizeof(t_stack) * j + 1);
	dat->sk_b = malloc(sizeof(t_stack) * j + 1);
	dat->aux = malloc(sizeof(t_stack) * j + 1);
	dat->sk_a[j].index = '\0';
	dat->sk_b[j].index = '\0';
	dat->aux[j].index = '\0';
	while (i < j)
	{
		dat->sk_a[i].nb = ft_atoi(array_arg[i]);
		dat->aux[i].nb = dat->sk_a[i].nb;
		dat->len_a++;
		i++;
	}
	ft_free_split(array_arg, i);
}

void	ft_numbers_in_many_argument(int ac, char **av, t_data *dat)
{
	int	i;

	i = 0;
	dat->sk_a = malloc(sizeof(t_stack) * ac);
	dat->sk_b = malloc(sizeof(t_stack) * ac);
	dat->aux = malloc(sizeof(t_stack) * ac);
	dat->sk_a[ac - 1].index = '\0';
	dat->sk_b[ac - 1].index = '\0';
	dat->aux[ac - 1].index = '\0';
	dat->mov = 0;
	while (i < ac - 1)
	{
		dat->sk_a[i].nb = ft_atoi(av[i + 1]);
		dat->aux[i].nb = dat->sk_a[i].nb;
		dat->len_a++;
		i++;
	}
	dat->len_n = dat->len_a;
}
