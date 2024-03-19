/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:49:51 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 18:03:58 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (min_stack_value(*stack) == tmp->content)
	{
		swap(stack, 'a', 1);
		rotate(stack, 'a', 1);
	}
	else if (max_stack_value(*stack) == tmp->content)
	{
		rotate(stack, 'a', 1);
		if (!stack_sorted(*stack))
			swap(stack, 'a', 1);
	}
	else
	{
		if (max_stack_value(*stack) == tmp->next->content)
			rrotate(stack, 'a', 1);
		else
			swap(stack, 'a', 1);
	}
}

int	sort(t_list **stack_a, t_list **stack_b, t_move **move)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	while (stack_a_size-- > 3 && stack_b_size++ < 2)
		push(stack_b, stack_a, 'b', 1);
	while (stack_a_size-- >= 3)
		sort_into_b(stack_a, stack_b, move);
	if (!stack_sorted(*stack_a))
		sort_three_stack(stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	while (stack_b_size-- > 0)
		sort_into_a(stack_a, stack_b, move);
	if (!stack_sorted(*stack_a))
	{
		fill_move(stack_a, min_stack_value(*stack_a), move);
		exec_move(*move, stack_a, stack_b, 'c');
	}
	return (0);
}
