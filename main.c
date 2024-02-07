/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:12:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/07 16:01:29 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "Libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc == 1)
		return (-1);
	parse(argv, stack_a);
}
