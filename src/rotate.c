/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:47 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/18 19:20:01 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, char c)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	else if (c == 'c')
		ft_printf("rr\n");
}

void	rrotate(t_list **stack, char c)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	else if (c == 'c')
		ft_printf("rrr\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, ' ');
	rotate(stack_b, 'c');
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a, ' ');
	rrotate(stack_b, 'c');
}
