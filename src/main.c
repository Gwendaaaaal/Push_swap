/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:12:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/18 19:23:26 by gholloco         ###   ########.fr       */
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
			ft_printf("%i", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf(" ");
		if (stack_b)
		{
			ft_printf("\t%i", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\n");
	ft_printf("a b\n");
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
		return (0);
	if (!parse(argv, &stack_a))
	{
		free_everything(&stack_a, &stack_b, &move);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (stack_sorted(stack_a))
		return (0);
	sort(&stack_a, &stack_b, &move);
	// print_stacks(stack_a, stack_b);
	free_everything(&stack_a, &stack_b, &move);
}
