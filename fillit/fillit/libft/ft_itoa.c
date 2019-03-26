/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:20:58 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/24 03:31:07 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_itoa(int n, int base)
{
	int		len;
	long	nb;
	char	*res;
	char	*str;

	str = "0123456789abcdef";
	len = n < 0 && base == 10 ? 1 : 0;
	nb = n < 0 && base == 10 ? -(long)n : n;
	len = ft_intlen(nb, len, base);
	len = (n == 0) ? 1 : len;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	nb = n < 0 && base == 10 ? -(long)n : n;
	while (nb > 0)
	{
		res[--len] = str[nb % 10];
		nb /= 10;
	}
	if (n < 0 && base == 10)
		res[0] = '-';
	return (res);
}

int main (void)
{
	printf("%s", ft_itoa(16618540, 2));
	return (0);
}
