/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufmann@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:24:54 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/14 12:34:29 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_whitespace(char *str);
int	check_sign(char *str, int *i_str);

int	ft_atoi(char *str)
{
	int	output;
	int	sign;
	int	i;

	output = 0;
	i = check_whitespace(str);
	sign = check_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		output *= 10;
		output += str[i] - '0';
		i++;
	}
	return (output * sign);
}

int	check_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	return (i);
}

int	check_sign(char *str, int *i_str)
{
	int	count_minus;
	int	sign;
	int	i;

	i = *i_str;
	count_minus = 0;
	sign = 0;
	while (sign == 0)
	{
		if (str[i] == '-')
			count_minus++;
		else if (str[i] != '+')
		{
			count_minus = count_minus % 2;
			if (count_minus == 0)
				sign = 1;
			else
				sign = -1;
		}
		i++;
	}
	*i_str = --i;
	return (sign);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("First try \"%s\" => %i\n", "	++++----3156kljdf45",
//		 ft_atoi("	++++----3156kljdf45"));
// 	printf("Second try \"%s\" => %i\n", "  	 ++---903156",
//		ft_atoi("  	 ++---903156"));
// 	printf("INT_MAX try \"%s\" => %i\n", "2147483647", ft_atoi("2147483647"));
// 	printf("INT_MIN try \"%s\" => %i\n", "-2147483648", ft_atoi("-2147483648"));
// 	printf("Zero try \"%s\" => %i\n", "0", ft_atoi("0"));
// 	return (0);
// }