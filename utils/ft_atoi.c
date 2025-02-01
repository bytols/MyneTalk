/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:07:51 by erocha-l          #+#    #+#             */
/*   Updated: 2024/08/01 15:51:29 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			i++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = (n * 10) + (*nptr - '0');
		nptr++;
	}
	if (i % 2 != 0)
		n *= -1;
	return (n);
}
/*#include <stdlib.h>
#include <stdio.h>
int main()
{
char    a[] = "2147483647";
ft_printf("%d\n", ft_atoi(a));
ft_printf("%d\n" , atoi(a) );
}*/
