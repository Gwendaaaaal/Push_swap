/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:42:32 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/18 16:05:04 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_everything(t_list **stack_a, t_list **stack_b, t_move **move)
{
	t_list	*tmp; 
	t_list	*node;

	if (move)
		free(*move);
	node = *stack_a;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	node = *stack_b;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	return (0);
}
