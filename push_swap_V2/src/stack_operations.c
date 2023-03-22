/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:56:48 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/12 14:56:51 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_move_right_sk_a(t_data *dat)
{
	int	i;

	i = dat->len_a;
	while (i > 0)
	{
		dat->sk_a[i] = dat->sk_a[i - 1];
		i--;
	}
}

void	ft_move_right_sk_b(t_data *dat)
{
	int	i;

	i = dat->len_b;
	while (i > 0)
	{
		dat->sk_b[i] = dat->sk_b[i - 1];
		i--;
	}
}

void	ft_move_left_sk_a(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->len_a)
	{
		dat->sk_a[i] = dat->sk_a[i + 1];
		i++;
	}
}

void	ft_move_left_sk_b(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->len_b)
	{
		dat->sk_b[i] = dat->sk_b[i + 1];
		i++;
	}
}
