/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:07:33 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 18:36:09 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	make_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strncmp(move, "ra\n", 3))
		rotate(stack_a, 'a', 0);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate(stack_b, 'b', 0);
	else if (!ft_strncmp(move, "rra\n", 3))
		rrotate(stack_a, 'a', 0);
	else if (!ft_strncmp(move, "rrb\n", 3))
		rrotate(stack_b, 'b', 0);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "sa\n", 3))
		swap(stack_a, 'a', 0);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap(stack_b, 'b', 0);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "pa\n", 3))
		push(stack_a, stack_b, 'a', 0);
	else if (!ft_strncmp(move, "pb\n", 3))
		push(stack_b, stack_a, 'b', 0);
	else
		return (0);
	return (1);
}

int checker(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!make_move(stack_a, stack_b, move))
			return(write(2, "Error\n", 6), free_everything(stack_a, stack_b, NULL), 0);
		free(move);
		move = get_next_line(0);
	}
	if (stack_sorted(*stack_a) && !ft_lstsize(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (argc == 1)
		return(free_everything(&stack_a, &stack_b, NULL), 0);
	if (!parse(argv, &stack_a))
	{
		free_everything(&stack_a, &stack_b, NULL);
		write(2, "Error\n", 6);
		return (0);
	}
	checker(&stack_a, &stack_b);
	free_everything(&stack_a, &stack_b, NULL);
	return (0);
}
