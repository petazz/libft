/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:50:48 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:48:12 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

static char	*ft_string(char *str, int len, int number)
{
	while (len != 0)
	{
		str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		number;
	char	*str;
	int		len;

	number = n;
	len = ft_len(number);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		number *= -1;
		len++;
	}
	if (number != 0)
		str = ft_string(str, len, number);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}
