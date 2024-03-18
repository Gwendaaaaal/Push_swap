/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:17:22 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/18 17:47:45 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	f_m(t_list *node, t_move **move, int value, t_list *stack)
{
	int	lst_size;
	int	r;

	(*move)->ra = node->rotate_to_top;
	(*move)->rra = node->rrotate_to_top;
	(*move)->rr = 0;
	(*move)->rrr = 0;
	r = 0;
	lst_size = ft_lstsize(stack);
	while (stack)
	{
		if (stack->content == value)
		{
			(*move)->rb = r;
			(*move)->rrb = lst_size - r;
			break ;
		}
		r++;
		stack = stack->next;
	}
	return (optimize_move(*move));
}

int	find_best_move(t_list **stack_a, t_list **stack_b, t_move **move)
{
	t_list	*tmp;
	t_move	*new_move;
	int		i;
	int		lst_size;

	new_move = init_move();
	tmp = *stack_a;
	i = 0;
	lst_size = ft_lstsize(*stack_a);
	while (tmp && new_move->nb_op != 0)
	{
		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = lst_size - i;
		if (find_above_value(*stack_b, tmp->content) == tmp->content
			|| find_below_value(*stack_b, tmp->content) == tmp->content)
			f_m(tmp, move, max_stack_value(*stack_b), *stack_b);
		else
			f_m(tmp, move, find_below_value(*stack_b, tmp->content), *stack_b);
		if (new_move->nb_op > (*move)->nb_op)
			new_move = duplicate_move(*move, new_move);
		tmp = tmp->next;
		i++;
	}
	(*move) = duplicate_move(new_move, *move);
	return (free(new_move), 0);
}

int	sort_into_b(t_list **stack_a, t_list **stack_b, t_move **move)
{
	find_best_move(stack_a, stack_b, move);
	exec_move(*move, stack_a, stack_b, 'b');
	return (0);
}
