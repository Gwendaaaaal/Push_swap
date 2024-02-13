/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:14:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/10 01:02:33 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>

// parse.c
int		parse(char **args, t_list **stack_a);

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
int	stack_sorted(t_list *stack);

#endif
