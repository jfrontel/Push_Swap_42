/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_III.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:10:04 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/21 17:10:11 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra_swap(t_data *dat, int wr)
{
	int	i;

	i = dat->len_a;
	ft_move_right_sk_a(dat);
	dat->sk_a[0] = dat->sk_a[i];
	if (wr == 1)
	{
		dat->mov++;
		write(1, "rra\n", 4);
	}
}

void	rrb_swap(t_data *dat, int wr)
{
	int	i;

	i = dat->len_b;
	ft_move_right_sk_b(dat);
	dat->sk_b[0] = dat->sk_b[i];
	if (wr == 1)
	{
		dat->mov++;
		write(1, "rrb\n", 4);
	}
}

void	rrr_swap(t_data *dat)
{
	rra_swap(dat, 0);
	rrb_swap(dat, 0);
	dat->mov++;
	write(1, "rrr\n", 4);
}
