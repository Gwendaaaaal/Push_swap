/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:34:13 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/13 15:00:36 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **to_push, t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) == 0)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	ft_lstadd_front(to_push, tmp);
}
