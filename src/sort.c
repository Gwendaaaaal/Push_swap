/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:49:51 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/19 23:42:51 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO : Func that will count which rotates to do depending on rotate/rrotate_to_top + below/above value
// rotate/rrotate_to_top.

int	fill_best_moves_value(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = ft_lstsize(*stack_a) - i;
		tmp->below_value = find_below_value(*stack_b, tmp->content);
		tmp->above_value = find_above_value(*stack_b, tmp->content);
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_b;
	i = 0;
	while (tmp)
	{

		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = ft_lstsize(*stack_b) - i;
		tmp->below_value = find_below_value(*stack_a, tmp->content);
		tmp->above_value = find_above_value(*stack_a, tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

// int	sort_into_b(t_list **stack_a, t_list **stack_b)
// {
//
// }

int	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		push(stack_b, stack_a);
	// while (ft_lstsize(*stack_a) > 3)
	// 	sort_into_b(stack_a, stack_b);
	fill_best_moves_value(stack_a, stack_b);
	return (0);
}
