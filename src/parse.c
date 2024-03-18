/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:44:00 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/18 16:06:32 by gholloco         ###   ########.fr       */
/*   Updated: 2024/02/09 23:02:25 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int	check_args(char **argv)
{
	int	i;
	int	num_len;

	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i]))
			return (0);
		num_len = ft_strlen(argv[i]);
		if (num_len == 11 && ft_strncmp(argv[i], "-2147483648", 11) > 0)
			return (0);
		if (num_len == 10 && ft_strncmp(argv[i], "2147483647", 10) > 0)
			return (0);
		if (num_len > 11)
			return (0);
		i++;
	}
	return (1);
}

static int	check_dup(t_list *stack, int number)
{
	while (stack)
	{
		if (stack->content == number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	parse(char **argv, t_list **stack_a)
{
	int		i;
	int		number;
	t_list	*tmp;

	i = 1;
	if (!check_args(argv))
		return (0);
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (!check_dup(*stack_a, number))
			return (0);
		tmp = ft_lstnew(number);
		if (!tmp)
			return (0);
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	return (1);
}
