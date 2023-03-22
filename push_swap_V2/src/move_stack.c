/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:31:30 by jfrontel          #+#    #+#             */
/*   Updated: 2023/03/16 16:31:33 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_move_stack_i(t_data *dat, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rr_swap(dat);
		a--;
		b--;
	}
	while (a > 0)
	{
		ra_swap(dat, 1);
		a--;
	}
	while (b > 0)
	{
		rb_swap(dat, 1);
		b--;
	}
	if (a == 0 && b == 0)
		pa_swap(dat);
}

void	ft_move_stack_ii(t_data *dat, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rrr_swap(dat);
		a--;
		b--;
	}
	while (a > 0)
	{
		rra_swap(dat, 1);
		a--;
	}
	while (b > 0)
	{
		rrb_swap(dat, 1);
		b--;
	}
	if (a == 0 && b == 0)
	{
		pa_swap(dat);
	}
}

void	ft_move_stack_iii(t_data *dat, int a, int b)
{
	while (a > 0)
	{
		rra_swap(dat, 1);
		a--;
	}
	while (b > 0)
	{
		rb_swap(dat, 1);
		b--;
	}
	if (a == 0 && b == 0)
		pa_swap(dat);
}

void	ft_move_stack_iv(t_data *dat, int a, int b)
{
	while (a > 0)
	{
		ra_swap(dat, 1);
		a--;
	}
	while (b > 0)
	{
		rrb_swap(dat, 1);
		b--;
	}
	if (a == 0 && b == 0)
		pa_swap(dat);
}

void	ft_search_minimal_cost(t_data *dat, int z, int temp)
{
	int	j;
	int	a;
	int	b;

	j = 0;
	while (j < z)
	{
		if (dat->sv_cost[j].cost_abs == temp)
		{
			a = ft_abs_valor(dat->sv_cost[j].cost_a);
			b = ft_abs_valor(dat->sv_cost[j].cost_b);
			if (dat->sv_cost[j].cost_a >= 0 && dat->sv_cost[j].cost_b >= 0)
				ft_move_stack_i(dat, a, b);
			else if (dat->sv_cost[j].cost_a <= 0 && dat->sv_cost[j].cost_b <= 0)
				ft_move_stack_ii(dat, a, b);
			else if (dat->sv_cost[j].cost_a <= 0 && dat->sv_cost[j].cost_b >= 0)
				ft_move_stack_iii(dat, a, b);
			else if (dat->sv_cost[j].cost_a >= 0 && dat->sv_cost[j].cost_b <= 0)
				ft_move_stack_iv(dat, a, b);
			break ;
		}
		j++;
	}
}
