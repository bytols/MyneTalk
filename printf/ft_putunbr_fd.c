/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:46:00 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/01 00:13:19 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putunbr_fd(unsigned int n, int fd, int *count)
{
	if (n > 9)
	{
		ft_putnbr_fd ((n / 10), fd, count);
		ft_putnbr_fd ((n % 10), fd, count);
	}
	else
	{
		n = n + 48;
		write (fd, &n, 1);
		*count += 1;
	}
}
