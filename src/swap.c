/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:31:08 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 18:38:30 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack, char c, char print)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (print)
		ft_printf("s%c\n", c);
}

void	ss(t_list **stack_a, t_list **stack_b, char print)
{
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	if (print)
		ft_printf("ss\n");
}
