/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:src/operations.c
/*   Created: 2024/02/08 16:07:47 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/12 17:21:30 by gholloco         ###   ########.fr       */
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
}

void	push(t_list **to_push, t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) == 0)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	ft_lstadd_front(to_push, tmp);
}
========
/*   Created: 2024/02/09 23:35:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/09 23:37:46 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
>>>>>>>> main:rotate.c

void	rotate(t_list **stack)
{
	t_list	*tmp;

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
