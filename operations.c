/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:47 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/08 17:06:40 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list *tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push(t_list **to_push, t_list **stack)
{
	t_list *tmp;

	tmp = (*to_push);
	(*to_push) = (*to_push)->next;

	ft_lstadd_front(stack, tmp);
}
