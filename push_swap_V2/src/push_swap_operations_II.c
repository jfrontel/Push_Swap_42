/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_II.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:34:52 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/16 19:34:54 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_swap(t_data *dat, int wr)
{
	int	i;

	i = dat->len_a;
	dat->sk_a[i] = dat->sk_a[0];
	ft_move_left_sk_a(dat);
	if (wr == 1)
	{
		dat->mov++;
		write(1, "ra\n", 3);
	}
}

void	rb_swap(t_data *dat, int wr)
{
	int	i;

	i = dat->len_b;
	dat->sk_b[i] = dat->sk_b[0];
	ft_move_left_sk_b(dat);
	if (wr == 1)
	{
		dat->mov++;
		write(1, "rb\n", 3);
	}
}

void	rr_swap(t_data *dat)
{
	ra_swap(dat, 0);
	rb_swap(dat, 0);
	dat->mov++;
	write(1, "rr\n", 3);
}
