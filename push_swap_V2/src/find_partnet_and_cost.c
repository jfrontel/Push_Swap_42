/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_partnet_and_cost.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:46:45 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/28 19:46:48 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_calculate_cost(t_data *dat, int position_a, int position_b)
{
	int	half;
	int	i;

	i = 0;
	half = (dat->len_a / 2);
	if (half % 2 == 0)
		half++;
	if (position_a <= half)
		dat->sk_a[position_a].cost = position_a;
	else if (position_a > half)
		dat->sk_a[position_a].cost = position_a - dat->len_a;
	i = 0;
	half = (dat->len_b / 2);
	if (half % 2 == 0)
		half++;
	if (position_b <= half)
		dat->sk_b[position_b].cost = position_b;
	else if (position_b > half)
		dat->sk_b[position_b].cost = position_b - dat->len_b;
}

void	ft_search_position(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->len_b)
	{	
		dat->sk_b[i].pos = i;
		i++;
	}
	i = 0;
	while (i < dat->len_a)
	{	
		dat->sk_a[i].pos = i;
		i++;
	}
}

void	ft_minimal_cost(t_data *dat, int z)
{
	int	j;
	int	temp;

	temp = dat->sv_cost[0].cost_abs;
	j = 1;
	while (j < z)
	{
		if (temp > dat->sv_cost[j].cost_abs)
			temp = dat->sv_cost[j].cost_abs;
		j++;
	}
	ft_search_minimal_cost(dat, z, temp);
	free(dat->sv_cost);
	if (dat->len_b > 0)
		ft_search_partnet(dat);
	else if (dat->len_b == 0)
	{
		while (ft_is_sorting(dat) != 1)
			rra_swap(dat, 1);
	}
	else
		return ;
}

void	ft_search_partnet(t_data *dat)
{
	int	i;
	int	j;
	int	z;

	z = 0;
	i = 0;
	dat->sv_cost = malloc(sizeof(t_cost) * dat->len_b);
	ft_search_position(dat);
	j = 0;
	while (j < dat->len_b)
	{
		i = search_partner_near(dat, j);
		dat->sv_cost[z].pos_a = i;
		dat->sv_cost[z].pos_b = j;
		ft_calculate_cost(dat, i, j);
		dat->sv_cost[z].cost_a = dat->sk_a[i].cost;
		dat->sv_cost[z].cost_b = dat->sk_b[j].cost;
		dat->sv_cost[z].cost_abs = ft_abs_valor(dat->sk_b[j].cost)
			+ ft_abs_valor(dat->sk_a[i].cost);
		z++;
		j++;
	}
	ft_minimal_cost(dat, z);
}

int	search_partner_near(t_data *dat, int j)
{
	int	z;
	int	i;

	i = dat->len_a - 1;
	z = 0;
	while (z < dat->len_a)
	{
		dat->aux[z] = dat->sk_a[z];
		z++;
	}
	ft_sort_index(dat, i);
	z = 0;
	while (z < dat->len_a)
		z++;
	i = 0;
	while (dat->sk_b[j].index > dat->aux[i].index)
		i++;
	z = 0;
	while (z < dat->len_a)
	{
		if (dat->sk_a[z].index == dat->aux[i].index)
			return (z);
		z++;
	}
	return (0);
}
