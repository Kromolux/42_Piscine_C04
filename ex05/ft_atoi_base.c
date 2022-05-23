/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufmann@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:30:21 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/14 15:58:41 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base);
int	ft_char_is_in_base(char *base, char c);
int	ft_char_is_unique(char *str, char c);
int	check_sign(char *str, int *i_str);

int	ft_atoi_base(char *str, char *base)
{
	int	output;
	int	sign;
	int	base_end;
	int	i;

	sign = 0;
	if (ft_check_base(base))
	{
		output = 0;
		i = 0;
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		sign = check_sign(str, &i);
		base_end = 0;
		while (base[base_end])
			base_end++;
		while (ft_char_is_in_base(base, str[i]) >= 0)
		{
			output *= base_end;
			output += ft_char_is_in_base(base, str[i]);
			i++;
		}
	}
	return (output * sign);
}

int	ft_check_base(char *base)
{
	int	i;
	int	condition;

	condition = -1;
	i = 0;
	while (base[i])
		i++;
	if (i <= 1)
		condition = 0;
	i = 0;
	while (condition == -1 && base[i])
	{
		if (base[i] < '!' || base[i] > '~')
			condition = 0;
		else if (base[i] == '-' || base[i] == '+')
			condition = 0;
		else if (!(ft_char_is_unique(base, base[i])))
			condition = 0;
		i++;
	}
	if (condition == -1)
		condition = 1;
	return (condition);
}

int	ft_char_is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_char_is_unique(char *str, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			result++;
		}
		i++;
	}
	if (result > 1)
		result = 0;
	return (result);
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

// needed functions for tests!
// #include <unistd.h>

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// void	ft_putnbr(int number)
// {
// 	char			output[12];
// 	unsigned int	temp;
// 	int				k;
// 	int				i;

// 	k = 1;
// 	if (number < 0)
// 		k = -1;
// 	i = 10;
// 	temp = (unsigned int) number * k;
// 	output[11] = '\0';
// 	while (temp > 9)
// 	{
// 		output[i] = (char)(temp % 10 + 48);
// 		temp = temp / 10;
// 		i--;
// 	}
// 	output[i] = (char)(temp % 10 + 48);
// 	if (number < 0)
// 	{
// 		i--;
// 		output[i] = '-';
// 	}
// 	ft_putstr(&output[i]);
// }

// int	main(void)
// {
// 	char	number_bases[7][17] = {{"01"},
// 								  {"0123456789"},
// 								  {"0123456789ABCDEF"},
// 								  {"poneyvif"},
// 								  {"koismf"},
// 								  {""},
// 								  {"012345677"}};
// 	char		test_str[7][17] = {{"2147483647"},
// 								  {"-2147483648"},
// 								  {"0"},
// 								  {"364"},
// 								  {"FFFFFF"},
// 								  {"on"},
// 								  {"1001010"}};
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		j = 0;
// 		while (j < 7)
// 		{
// 			ft_putstr("String Number = \"");
// 			ft_putstr(test_str[j]);
// 			ft_putstr("\" number base = \"");
// 			ft_putstr(number_bases[i]);
// 			ft_putstr("\" => ");
// 			ft_putnbr(ft_atoi_base(test_str[j], number_bases[i]));
// 			write(1, "\n", 1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
