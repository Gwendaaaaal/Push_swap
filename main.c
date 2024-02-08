/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:12:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/08 15:49:56 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a)
	{
		printf("%i\n", *((int *) stack_a->content));
		stack_a = stack_a->next;
	}
	printf("- -\n");
	printf("a b\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (-1);
	if (!parse(argv, &stack_a))
		return (-1);
	print_stacks(stack_a, stack_b);
}
