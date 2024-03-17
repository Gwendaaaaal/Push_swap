/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:31:08 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/22 17:25:41 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	printf("sa\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
