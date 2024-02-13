/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:35:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/09 23:37:46 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack) < 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	rrotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 1)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
