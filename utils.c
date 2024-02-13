/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:52:49 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/10 01:02:26 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *stack)
{
	int		i;

	if (!stack)
		return (0);
	i = *((int *) stack->content);
	while(stack)
	{
		if (*((int *) stack->content) < i)
				return (0);
		i = *((int *) stack->content);
		stack = stack->next;
	}
	return (1);
}
