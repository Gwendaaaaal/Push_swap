/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:47 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 17:49:02 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, char c, char print)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (print)
		ft_printf("r%c\n", c);
}

void	rrotate(t_list **stack, char c, char print)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
	if (print)
		ft_printf("rr%c\n", c);
}

void	rr(t_list **stack_a, t_list **stack_b, char print)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	if (print)
		ft_printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, char print)
{
	rrotate(stack_a, 'a', 0);
	rrotate(stack_b, 'b', 0);
	if (print)
		ft_printf("rrr\n");
}
