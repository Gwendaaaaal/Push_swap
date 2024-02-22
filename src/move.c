/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:45 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/22 04:04:08 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_move	*duplicate_move(t_move *to_dup)
{
	t_move *tmp;

	tmp = init_move();
	tmp->ra = to_dup->ra;
	tmp->rb = to_dup->rb;
	tmp->rr = to_dup->rr;
	tmp->rra = to_dup->rra;
	tmp->rrb = to_dup->rrb;
	tmp->rrr = to_dup->rrr;
	tmp->nb_op = to_dup->nb_op;
	return (tmp);
}

void	exec_move(t_move *move, t_list **stack_a, t_list **stack_b)
{
	// printf("Before exec :\nmove_ra = %i, move_rb = %i, move_rr = %i\nmove_rra = %i, move_rrb = %i, move_rrr = %i\n", move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
	while (move->ra-- > 0)
		rotate(stack_a, 'a');
	while (move->rb-- > 0)
		rotate(stack_b, 'b');
	while (move->rr-- > 0)
		rr(stack_a, stack_b);
	while (move->rra-- > 0)
		rrotate(stack_a, 'a');
	while (move->rrb-- > 0)
		rrotate(stack_b, 'b');
	while (move->rrr-- > 0)
		rrr(stack_a, stack_b);
	push(stack_b, stack_a, 'b');
	// printf("After exec :\nmove_ra = %i, move_rb = %i, move_rr = %i\nmove_rra = %i, move_rrb = %i, move_rrr = %i\n", move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
}

// TOOD : LIGNE 65/67 TRES CURIEUSES

int	optimize_move(t_move *move)
{
	int nb_op;

	// printf("Before opti :\nmove_ra = %i, move_rb = %i, move_rr = %i\nmove_rra = %i, move_rrb = %i, move_rrr = %i\n", move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
	if (move->ra <= move->rra && move->rb <= move->rrb && move->ra && move->rb)
		while (move->ra > 0 && move->rb > 0)
		{
			move->rr += 1;
			move->ra--;
			move->rb--;
			move->rra = 0;
			move->rrb = 0;
		}
	else if ((move->rra <= move->ra) && (move->rrb <= move->rb) && move->rra && move ->rrb)
		while (move->rra > 0 && move ->rrb > 0)
		{
			move->rrr++;
			move->rra--;
			move->rrb--;
			move->ra = 0;
			move->rb = 0;
		}
	else
	{
		if (move->ra < move->rra && move->rra)
			move->rra = 0;
		else if (move->rra < move ->ra && move->ra)
			move->ra = 0;
		if (move->rb <= move->rrb && move->rrb)
			move->rrb = 0;
		else if (move->rrb <= move->rb && move->rb)
			move->rb = 0;
	}
	nb_op = move->rrr + move->rr + move->ra + move->rb + move->rra
		+ move->rrb + 1;
	// printf("After opti :\nmove_ra = %i, move_rb = %i, move_rr = %i\nmove_rra = %i, move_rrb = %i, move_rrr = %i\n", move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
	// printf("\t\t COUTE %i OPERATIONS\n", nb_op);
	move->nb_op = nb_op;
	return (nb_op);
}

t_move	*init_move(void)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->nb_op = 2147483647;
	if (!move)
		return (NULL);
	return (move);
}
