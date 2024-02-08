/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:14:23 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/08 16:00:54 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>

// parse.c
int		parse(char **args, t_list **stack_a);

// maic.c
void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
