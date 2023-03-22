/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:56:38 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/26 17:56:41 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs_valor(int cost)
{
	if (cost < 0)
		return (-cost);
	return (cost);
}

int	ft_is_sorting(t_data *dat)
{
	int	j;
	int	i;

	i = dat->len_a - 1;
	j = 0;
	while (j < i)
	{
		if (dat->sk_a[j].nb > dat->sk_a[j + 1].nb)
			return (0);
		j++;
	}
	return (1);
}

void	ft_sorting_three_nb(t_data *dat)
{
	if (ft_is_sorting(dat) == 1)
		return ;
	if (dat->sk_a[0].nb < dat->sk_a[2].nb)
		sa_swap(dat, 1);
	if (dat->sk_a[0].nb > dat->sk_a[1].nb && dat->sk_a[0].nb > dat->sk_a[1].nb
	 	&& dat->sk_a[1].nb > dat->sk_a[2].nb)
	 	sa_swap(dat, 1);
	if (dat->sk_a[0].nb < dat->sk_a[1].nb && dat->sk_a[0].nb > dat->sk_a[2].nb
	 	&& dat->sk_a[1].nb > dat->sk_a[2].nb)
	 	rra_swap(dat, 1);
	if (dat->sk_a[0].nb > dat->sk_a[1].nb && dat->sk_a[0].nb > dat->sk_a[2].nb
	 	&& dat->sk_a[1].nb < dat->sk_a[2].nb)
		ra_swap(dat, 1);
}

void	ft_sorting_many_nb(t_data *dat)
{
	int		i;
	int		aux;

	aux = dat->len_a;
	i = 0;
	if (ft_is_sorting(dat) == 1)
		return ;
	while (i < aux)
	{
		if (dat->sk_a[0].index <= aux - 3)
			pb_swap(dat);
		else
			ra_swap(dat, 1);
	i++;
	}
	return ;
}

void	ft_sorting_nb(t_data *dat)
{
	if (dat->len_a == 2 && dat->sk_a[0].nb > dat->sk_a[1].nb)
		sa_swap(dat, 1);
	else if (dat->len_a > 3)
		ft_sorting_many_nb(dat);
	if (dat->len_a == 3)
		ft_sorting_three_nb(dat);
	ft_search_partnet(dat);
	return ;
}
