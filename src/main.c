/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:12:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/21 17:36:28 by gholloco         ###   ########.fr       */
/*   Updated: 2024/02/10 01:13:03 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%i %i", stack_a->content, stack_a->nb_op);
			stack_a = stack_a->next;
		}
		else
			printf(" ");
		if (stack_b)
		{
			printf("\t%i", stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("- -\n");
	printf("a b\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_move	*move;

	stack_a = NULL;
	stack_b = NULL;
	move = init_move();
	if (argc == 1)
		return (-1);
	if (!parse(argv, &stack_a))
		return (-1);
	if (stack_sorted(stack_a))
		return (printf("STACK SORTED"));
	sort(&stack_a, &stack_b, &move);
	print_stacks(stack_a, stack_b);
	printf("above value of %i is %i\n", 7, find_above_value(stack_b, 7));
	printf("below value of %i is %i\n", 7, find_below_value(stack_b, 7));
}
