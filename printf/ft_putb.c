/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:32:55 by erocha-l          #+#    #+#             */
/*   Updated: 2025/01/28 19:23:49 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putb(unsigned int n, int fd, char *base, int *count)
{
	if (n > 15)
	{
		ft_putb ((n / 16), fd, base, count);
		ft_putb ((n % 16), fd, base, count);
	}
	else
	{
		n = base[n];
		write (fd, &n, 1);
		*count += 1;
	}
}
