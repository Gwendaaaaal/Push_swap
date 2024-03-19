/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:34:13 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 18:03:14 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **to_push, t_list **stack, char c, char print)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) == 0)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	ft_lstadd_front(to_push, tmp);
	if (print)
		ft_printf("p%c\n", c);
}
