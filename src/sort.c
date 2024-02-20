/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:49:51 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/20 16:18:44 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO : Func that will count which rotates to do depending on 
// rotate/rrotate_to_top + below/above value
// rotate/rrotate_to_top.

// t_move calculate_nb_op(t_list *stack, int value, int r, int rr)
// {
// 
// }

int	fill_list_values(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		lst_size;

	tmp = *stack_b;
	i = 0;
	lst_size = ft_lstsize(*stack_b);
	while (tmp)
	{
		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = lst_size - i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_a;
	i = 0;
	lst_size = ft_lstsize(*stack_a);
	while (tmp)
	{
		tmp->rotate_to_top = i;
		tmp->rrotate_to_top = lst_size - i;
		if (find_above_value(*stack_b, tmp->content) == tmp->content
			|| find_below_value(*stack_b, tmp->content) == tmp->content) // value = le nouveau min/max de stack_b
			tmp->nb_op += 0; // += le nombre de rotation du max de stack_b
		else
			tmp->nb_op += 0; // += le nombre de rotations de below_value
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	sort_into_b(t_list **stack_a, t_list **stack_b)
{
	fill_list_values(stack_a, stack_b);
	return (0);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	while (stack_a_size-- > 3 && stack_b_size++ < 2)
		push(stack_b, stack_a);
	while (stack_a_size-- > 3)
		sort_into_b(stack_a, stack_b);
	return (0);
}
