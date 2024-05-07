/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:56:27 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/07 17:29:28 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fill_move(t_list **stack_a, int value, t_move **move)
{
	t_list	*tmp;
	int		i;
	int		lst_size;

	i = 0;
	tmp = *stack_a;
	lst_size = ft_lstsize(*stack_a);
	(*move)->rb = 0;
	(*move)->rr = 0;
	(*move)->rrb = 0;
	(*move)->rrr = 0;
	while (tmp)
	{
		if (tmp->content == value)
		{
			(*move)->ra = i;
			(*move)->rra = lst_size - i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (optimize_move(*move));
}

int	find_best_move_a(t_list **stack_a, t_list **stack_b, t_move **move)
{
	t_list	*tmp;
	int		above_value;

	tmp = *stack_b;
	above_value = find_above_value(*stack_a, tmp->content);
	if (above_value == tmp->content)
		fill_move(stack_a, min_stack_value(*stack_a), move);
	else
		fill_move(stack_a, above_value, move);
	return (0);
}

int	sort_into_a(t_list **stack_a, t_list **stack_b, t_move **move)
{
	find_best_move_a(stack_a, stack_b, move);
	exec_move(*move, stack_a, stack_b, 'a');
	return (0);
}
