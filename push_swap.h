/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:14:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/16 02:26:13 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>

// parse.c
int		parse(char **args, t_list **stack_a);

// sort.c
int	sort(t_list **stack_a, t_list **stack_b);

// swap.c
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

// push.c
void	push(t_list **to_push, t_list **stack);

// rotate.c
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// main.c
void	print_stacks(t_list *stack_a, t_list *stack_b);

// utils.c
int	max_stack_value(t_list *stack);
int	min_stack_value(t_list *stack);
int find_above_value(t_list *stack, int value);
int	find_below_value(t_list *stack, int value);
int	stack_sorted(t_list *stack);

#endif
