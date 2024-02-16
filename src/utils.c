/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:52:49 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/16 01:47:00 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_stack_value(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return max;
}

int	min_stack_value(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return min;
}

int find_above_value(t_list *stack, int value)
{
	int	above_value;

	above_value = max_stack_value(stack);
	while (stack)
	{
		if (stack->content > value && stack->content < above_value)
			above_value = stack->content;
		stack = stack->next;
	}
	return (above_value);
}

int	find_below_value(t_list *stack, int value)
{
	int	below_value;

	below_value = min_stack_value(stack);
	while (stack)
	{
		if (stack->content <= value && stack->content > below_value)
			below_value = stack->content; 
		stack = stack->next;
	}
	return (below_value);
}

int	stack_sorted(t_list *stack)
{
	int		i;

	if (!stack)
		return (0);
	i = stack->content;
	while(stack)
	{
		if (stack->content < i)
			return (0);
		i = stack->content;
		stack = stack->next;
	}
	return (1);
}
