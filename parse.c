/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:44:00 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/06 18:22:07 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

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

static int	check_args(char *str)
{
	int i;

	i = 1;
	
}
int	parse(char **args)
{
	int	i;

	i = 1;
	if (!check_argsi(argv))
		return (0);
	while (args[i])
	{
		if (check_number(args[i]))
			printf("%i\n", ft_atoi(args[i]));
		else
			printf("Error\n");
		i++;
	}
	return (1);
}
