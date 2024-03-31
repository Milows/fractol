/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:16:11 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/12 17:20:38 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*genera una string que represente el valor entero recibido como argumento*/
static int	digit_len(long int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	fill_str(char *str, long int nb, int is_negative, int i)
{
	if (!str)
	{
		str = NULL;
		return ;
	}
	str[i--] = '\0';
	if (is_negative)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			i;
	int			is_negative;

	is_negative = n < 0;
	nb = n;
	if (is_negative)
		nb = -nb;
	i = digit_len(n) + is_negative;
	str = (char *)malloc(sizeof(char) * (i + 1));
	fill_str(str, nb, is_negative, i);
	return (str);
}
