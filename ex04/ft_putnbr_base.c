/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufmann@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:27:21 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/14 14:03:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_check_base(char *base);
unsigned int	ft_strlen(char *str);
int				ft_char_is_unique(char *str, char c);
void			ft_printf_reverse_str(char *str);

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	temp_nbr;
	unsigned int	base_number;
	int				i;
	char			output[33];

	if (ft_check_base(base))
	{
		base_number = ft_strlen(base);
		temp_nbr = (unsigned int) nbr;
		if (nbr < 0)
		{
			temp_nbr = (unsigned int)(nbr * -1);
			write(1, "-", 1);
		}
		i = 0;
		while (temp_nbr > (base_number - 1))
		{
			output[i] = (base[temp_nbr % base_number]);
			temp_nbr /= base_number;
			i++;
		}
		output[i] = (base[temp_nbr % base_number]);
		output[i + 1] = '\0';
		ft_printf_reverse_str(output);
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	condition;

	condition = -1;
	i = 0;
	if (ft_strlen(base) <= 1)
		condition = 0;
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

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	ft_printf_reverse_str(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

// needed functions for tests!
// #include <limits.h>

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
// 							  {"0123456789"},
// 							  {"0123456789ABCDEF"},
// 							  {"poneyvif"},
// 							  {"koismf"},
// 							  {""},
// 							  {"012345677"}};
// 	int		test_tab[4] = {INT_MAX, INT_MIN, 0, 364};
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		j = 0;
// 		while (j < 4)
// 		{
// 			ft_putstr("Number = \"");
// 			ft_putnbr(test_tab[j]);
// 			ft_putstr("\" number base = \"");
// 			ft_putstr(number_bases[i]);
// 			ft_putstr("\" => ");
// 			ft_putnbr_base(test_tab[j], number_bases[i]);
// 			write(1, "\n", 1);
// 			j++;
// 		}
// 		i++;
// 	}

// 	return (0);
// }