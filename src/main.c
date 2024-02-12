/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:12:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/12 17:20:30 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%i", stack_a->content);
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

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (-1);
	if (!parse(argv, &stack_a))
		return (-1);
	print_stacks(stack_a, stack_b);
	printf("SWAP A\n");
	swap(&stack_a);
	print_stacks(stack_a, stack_b);
	printf("SWAP A\n");
	swap(&stack_a);
	print_stacks(stack_a, stack_b);
	printf("PUSH B\n");
	push(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);
	printf("PUSH B\n");
	push(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);
	printf("PUSH B\n");
	push(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);
	printf("PUSH B\n");
	push(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);
	printf("PUSH A\n");
	push(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	printf("ROTATE A\n");
	rotate(&stack_a);
	print_stacks(stack_a, stack_b);
	printf("ROTATE B\n");
	rotate(&stack_b);
	print_stacks(stack_a, stack_b);
}