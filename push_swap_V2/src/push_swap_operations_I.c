/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_I.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:37:27 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/15 12:37:31 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_swap(t_data *dat, int wr)
{
	if (dat->sk_a[0].index && dat->sk_a[1].index)
	{
		dat->aux[0] = dat->sk_a[0];
		dat->sk_a[0] = dat->sk_a[1];
		dat->sk_a[1] = dat->aux[0];
		dat->mov++;
		if (wr == 1)
			write (1, "sa\n", 3);
	}
}

void	sb_swap(t_data *dat, int wr)
{
	if (dat->sk_b[0].index && dat->sk_b[1].index)
	{
		dat->aux[0] = dat->sk_b[0];
		dat->sk_b[0] = dat->sk_b[1];
		dat->sk_b[1] = dat->aux[0];
		dat->mov++;
		if (wr == 1)
			write (1, "sb\n", 3);
	}
}

void	ss_swap(t_data *dat)
{
	sa_swap(dat, 0);
	sb_swap(dat, 0);
	dat->mov++;
	write(1, "ss\n", 3);
}

void	pa_swap(t_data *dat)
{
	if (dat->len_b > 0)
	{
		ft_move_right_sk_a(dat);
		dat->sk_a[0] = dat->sk_b[0];
		dat->len_a++;
		ft_move_left_sk_b(dat);
		dat->len_b--;
		dat->mov++;
		write(1, "pa\n", 3);
	}
}

void	pb_swap(t_data *dat)
{
	if (dat->len_a > 0)
	{
		ft_move_right_sk_b(dat);
		dat->sk_b[0] = dat->sk_a[0];
		dat->len_b++;
		ft_move_left_sk_a(dat);
		dat->len_a--;
		dat->mov++;
		write(1, "pb\n", 3);
	}
}
