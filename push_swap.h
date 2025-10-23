/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:50:35 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/11 13:39:11 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				valeur;
	struct s_pile	*next;
}	t_pile;

/* Actions */
void	push(t_pile **p, int value);
void	swap(t_pile **p);
void	rotate(t_pile **p);
void	reverse_rotate(t_pile **p);
void	sa(t_pile **p1);
void	ra(t_pile **p1);
void	rra(t_pile **p1);

/* Sorting */
void	bit_sorting(t_pile **p1, t_pile **p2, int size, int max_bits);
void	tree_number_sorting(t_pile **p1);
void	five_number_sorting(t_pile **p1, t_pile **p2, int nb);

/* Utils */
long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	free_split(char **split);
void	normalize(t_pile *head);
int		pop(t_pile **p);
void	print_list(t_pile *head);
int		str_counter(char **str);
int		bit_checker(t_pile *p, int nb);
int		is_sorted(t_pile *p1);
int		is_duplicate(t_pile *p);
int		is_valid_argument(char **argv, int argskip);
int		find_smallest_value(t_pile *tmp, int min_val);
void	push_everything_in_p1(t_pile **p2, t_pile **p1);
int		handle_input(int argc, char **argv, t_pile **p1, int argskip);
void	init_variables(t_pile **p1, t_pile **p2, int *argskip);
int		count_max_bits(t_pile *p1);
void	normalize_and_sort(int argc, t_pile **p1, t_pile **p2);
int		is_valid_number(char *str);
void	sorting_handler(int argc, t_pile **p1, t_pile **p2, int max_bits);
int		handle_single_arg(char **argv, char ***numbers, int *size,
			int *argskip);
#endif