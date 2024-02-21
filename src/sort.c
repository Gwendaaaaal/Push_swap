/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:49:51 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/21 20:17:52 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO : Func that will count which rotates to do depending on 
// rotate/rrotate_to_top + below/above value
// rotate/rrotate_to_top.

int	calculate_nb_op(t_list *node, t_move **move, int value, t_list *stack)
{
	int lst_size;
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
			printf("We found %i value in stack_b at index r = %i, lstsize of stack b is : %i\n", value, r, lst_size);
			(*move)->rb = r;
			(*move)->rrb = lst_size - r;
			break;
		}
		r++;
		stack = stack->next;
	}
	printf("Optimize_move for %i placing above %i : \n", node->content, value);
	return (optimize_move(*move));
}

int	fill_list_values(t_list **stack_a, t_list **stack_b, t_move **move)
{
	t_list	*tmp;
	t_move *new_move;
	int		i;
	int		lst_size;

	new_move = init_move();
	tmp = *stack_a;
	i = 0;
	lst_size = ft_lstsize(*stack_a);
	while (tmp)
	{
		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = lst_size - i;
		if (find_above_value(*stack_b, tmp->content) == tmp->content
			|| find_below_value(*stack_b, tmp->content) == tmp->content) // value = le nouveau min/max de stack_b
			tmp->nb_op = calculate_nb_op(tmp, move, max_stack_value(*stack_b), *stack_b); // += le nombre d'operations
		else
			tmp->nb_op = calculate_nb_op(tmp, move, find_below_value(*stack_b, tmp->content), *stack_b); // += le nombre de rotations
		if (new_move->nb_op > (*move)->nb_op)
			new_move = (*move);
		tmp = tmp->next;
		i++;
	}
	(*move) = new_move;
	return (0);
}

// TODO : If move->nb_op = 0 at one point, no need to get another move.

int	sort_into_b(t_list **stack_a, t_list **stack_b, t_move **move)
{
	fill_list_values(stack_a, stack_b, move);
	return (0);
}

int	sort(t_list **stack_a, t_list **stack_b, t_move **move)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	while (stack_a_size-- > 3 && stack_b_size++ < 4)
		push(stack_b, stack_a);
	while (stack_a_size-- > 3)
		sort_into_b(stack_a, stack_b, move);
	return (0);
}
