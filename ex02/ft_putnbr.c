/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufmann@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:23:35 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/14 12:33:05 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putnbr(int number)
{
	char			output[12];
	unsigned int	temp;
	int				k;
	int				i;

	k = 1;
	if (number < 0)
		k = -1;
	i = 10;
	temp = (unsigned int) number * k;
	output[11] = '\0';
	while (temp > 9)
	{
		output[i] = (char)(temp % 10 + 48);
		temp = temp / 10;
		i--;
	}
	output[i] = (char)(temp % 10 + 48);
	if (number < 0)
	{
		i--;
		output[i] = '-';
	}
	ft_putstr(&output[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// #include <limits.h>
// int	main(void)
// {
// 	ft_putnbr(INT_MAX);
// 	write(1, "\n", 1);
// 	ft_putnbr(INT_MIN);
// 	write(1, "\n", 1);
// 	ft_putnbr(0);
// 	write(1, "\n", 1);
// 	ft_putnbr(-1665);
// 	write(1, "\n", 1);
// 	ft_putnbr(+8313);
// 	write(1, "\n", 1);
// 	return (0);
// }