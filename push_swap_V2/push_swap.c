/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:11:09 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/12 14:11:12 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	ft_leaks(void)
{
	system("leaks push_swap");
}

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_exit(t_data dat)
{
	free(dat.sk_a);
	free(dat.sk_b);
	free(dat.aux);
}

int	main(int ac, char **av)
{
	t_data			dat;

	//atexit(ft_leaks);
	dat.len_a = 0;
	dat.len_b = 0;
	if (ac < 2 || av[1][0] == '\0')
		return (0);
	if (ft_validate_av(ac, av, &dat) == -1)
		ft_error();
	ft_search_index(&dat);
	ft_sorting_nb(&dat);
	ft_free_exit(dat);
	return (0);
}
