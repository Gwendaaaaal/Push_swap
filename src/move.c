/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:45 by gholloco          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:07 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_move	*duplicate_move(t_move *to_dup, t_move *to_free, t_list **stack_a, t_list **stack_b)
{
	t_move	*tmp;

	free(to_free);
	tmp = init_move(stack_a, stack_b);
	tmp->ra = to_dup->ra;
	tmp->rb = to_dup->rb;
	tmp->rr = to_dup->rr;
	tmp->rra = to_dup->rra;
	tmp->rrb = to_dup->rrb;
	tmp->rrr = to_dup->rrr;
	tmp->nb_op = to_dup->nb_op;
	return (tmp);
}

void	exec_move(t_move *move, t_list **stack_a, t_list **stack_b, char c)
{
	while (move->ra-- > 0)
		rotate(stack_a, 'a', 1);
	while (move->rb-- > 0)
		rotate(stack_b, 'b', 1);
	while (move->rr-- > 0)
		rr(stack_a, stack_b, 1);
	while (move->rra-- > 0)
		rrotate(stack_a, 'a', 1);
	while (move->rrb-- > 0)
		rrotate(stack_b, 'b', 1);
	while (move->rrr-- > 0)
		rrr(stack_a, stack_b, 1);
	if (c == 'a')
		push(stack_a, stack_b, 'a', 1);
	if (c == 'b')
		push(stack_b, stack_a, 'b', 1);
}

int	optimize_move_2(t_move *move, int a)
{
	int	nb_op;

	if (a == 2)
	{
		if (move->ra <= move->rra && move->rra)
			move->rra = 0;
		else if (move->rra <= move ->ra && move->ra)
			move->ra = 0;
		if (move->rb <= move->rrb && move->rrb)
			move->rrb = 0;
		else if (move->rrb <= move->rb && move->rb)
			move->rb = 0;
	}
	nb_op = move->rrr + move->rr + move->ra + move->rb + move->rra
		+ move->rrb + 1;
	move->nb_op = nb_op;
	return (nb_op);
}

int	optimize_move(t_move *m)
{
	if (m->ra <= m->rra && m->rb <= m->rrb && m->ra && m->rb)
	{
		while (m->ra > 0 && m->rb > 0)
		{
			m->rr += 1;
			m->ra--;
			m->rb--;
			m->rra = 0;
			m->rrb = 0;
		}
	}
	else if ((m->rra <= m->ra) && (m->rrb <= m->rb) && m->rra && m->rrb)
	{
		while (m->rra > 0 && m->rrb > 0)
		{
			m->rrr++;
			m->rra--;
			m->rrb--;
			m->ra = 0;
			m->rb = 0;
		}
	}
	else
		return (optimize_move_2(m, 2));
	return (optimize_move_2(m, 1));
}

t_move	*init_move(t_list **stack_a, t_list **stack_b)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
	{
		free_everything(stack_a, stack_b, NULL);
		exit(0);
	}
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->nb_op = 2147483647;
	return (move);
}
