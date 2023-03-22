/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:11:21 by jfrontel          #+#    #+#             */
/*   Updated: 2022/09/12 14:11:24 by jfrontel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

// nb : el número a ordenar;
// index : su índice en la lista de todos los valores a ordenar;
// pos : su posición actual en la pila en la que se encuentra este número;

typedef struct s_cost
{
	int				pos_a;
	int				pos_b;
	int				cost_a;
	int				cost_b;
	int				cost_abs;
}				t_cost;

typedef struct s_stack
{
	int				nb;
	int				pos;
	int				index;
	int				cost;
	int				cost_total;
}				t_stack;

typedef struct s_data
{
	t_stack			*sk_a;
	t_stack			*sk_b;
	t_cost			*sv_cost;
	int				len_a;
	int				len_b;
	int				len_n;
	int				mov;
	t_stack			*aux;
}				t_data;

/*		PUSH_SWAP_UTILS.C		*/
long long	ft_atoi(const char *nptr);
char		*ft_strchr(const char *str, int c);

/*		FT_SPLIT		*/
char		**ft_split(char const *s, char c);

/*		STACK_OPERATIONS.C		*/
void		ft_move_left_sk_a(t_data *dat);
void		ft_move_left_sk_b(t_data *dat);
void		ft_move_right_sk_a(t_data *dat);
void		ft_move_right_sk_b(t_data *dat);

/*		STACK_OPERATIONS_I		*/
void		sa_swap(t_data *dat, int wr);
void		sb_swap(t_data *dat, int wr);
void		ss_swap(t_data *dat);
void		pa_swap(t_data *dat);
void		pb_swap(t_data *dat);

/*		STACK_OPERATIONS_II		*/
void		ra_swap(t_data *dat, int wr);
void		rb_swap(t_data *dat, int wr);
void		rr_swap(t_data *dat);

/*		STACK_OPERATIONS_III	*/
void		rra_swap(t_data *dat, int wr);
void		rrb_swap(t_data *dat, int wr);
void		rrr_swap(t_data *dat);

/*		VALIDATE_ARG	*/
int			ft_repeated_nb(t_data *dat);
int			ft_count_array(char **array_arg);
int			ft_argument_are_nb_1(char **av);
int			ft_argument_are_nb_2(int ac, char **av);
int			ft_validate_av(int ac, char **av, t_data *dat);

/*		ARGUMENT_AND_INDEX		*/
void		ft_sort_array(t_data *dat);
void		ft_sort_index(t_data *dat, int i);
void		ft_search_index(t_data *dat);
void		ft_numbers_in_one_argument(char **av, t_data *dat);
void		ft_numbers_in_many_argument(int ac, char **av, t_data *dat);

/*		SORT_NUMBER		*/
int			ft_abs_valor(int cost);
void		ft_sorting_many_nb(t_data *dat);
void		ft_sorting_three_nb(t_data *dat);
int			ft_is_sorting(t_data *dat);
void		ft_sorting_nb(t_data *dat);

/*		FIND_PARTNET_AND_COST	*/
void		ft_calculate_cost(t_data *dat, int position_a, int position_b);
void		ft_search_partnet(t_data *dat);
void		ft_search_position(t_data *dat);
void		ft_minimal_cost(t_data *dat, int z);
int			search_partner_near(t_data *dat, int j);

/*		MOVE_STACK		*/
void		ft_move_stack_i(t_data *dat, int a, int b);
void		ft_move_stack_ii(t_data *dat, int a, int b);
void		ft_move_stack_iii(t_data *dat, int a, int b);
void		ft_move_stack_iv(t_data *dat, int a, int b);
void		ft_search_minimal_cost(t_data *dat, int z, int temp);

/*		VALIDATE_OVERFLOW		*/
void		ft_free_split(char **array_arg, int i);
int			ft_overflow_in_one_arg(char **av, t_data *dat);
int			ft_overflow(int ac, char **av, t_data *dat);

#endif
